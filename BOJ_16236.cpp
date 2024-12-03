#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

struct Shark
{
  int x, y, size, eaten;
};

int N;
vector<vector<int>> grid;
Shark shark;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

bool is_in_bounds(int x, int y)
{
  return x >= 0 && x < N && y >= 0 && y < N;
}

int bfs()
{
  vector<vector<bool>> visited(N, vector<bool>(N, false));
  queue<tuple<int, int, int>> q;
  q.push({shark.x, shark.y, 0});
  visited[shark.x][shark.y] = true;

  vector<tuple<int, int, int>> fish_candidates;

  while (!q.empty())
  {
    int x, y, dist;
    tie(x, y, dist) = q.front();
    q.pop();

    for (int i = 0; i < 4; ++i)
    {
      int nx = x + dx[i], ny = y + dy[i];

      if (is_in_bounds(nx, ny) && !visited[nx][ny] && grid[nx][ny] <= shark.size)
      {
        visited[nx][ny] = true;
        q.push({nx, ny, dist + 1});

        if (grid[nx][ny] > 0 && grid[nx][ny] < shark.size)
        {
          fish_candidates.push_back({dist + 1, nx, ny});
        }
      }
    }
  }

  if (fish_candidates.empty())
    return 0;

  sort(fish_candidates.begin(), fish_candidates.end());
  int dist, fish_x, fish_y;
  tie(dist, fish_x, fish_y) = fish_candidates[0];

  shark.x = fish_x;
  shark.y = fish_y;
  shark.eaten++;
  if (shark.eaten == shark.size)
  {
    shark.size++;
    shark.eaten = 0;
  }

  grid[fish_x][fish_y] = 0;

  return dist;
}

int main()
{
  cin >> N;
  grid.resize(N, vector<int>(N));

  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < N; ++j)
    {
      cin >> grid[i][j];
      if (grid[i][j] == 9)
      {
        shark = {i, j, 2, 0};
        grid[i][j] = 0;
      }
    }
  }

  int total_time = 0;
  while (true)
  {
    int time_spent = bfs();
    if (time_spent == 0)
      break;
    total_time += time_spent;
  }

  cout << total_time << endl;
  return 0;
}