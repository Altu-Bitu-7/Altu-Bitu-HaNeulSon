#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 101;
bool grid[MAX][MAX];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

// 드래곤 커브
void drawDragonCurve(int x, int y, int d, int g)
{
  vector<int> directions;
  directions.push_back(d);

  for (int i = 0; i < g; ++i)
  {
    int size = directions.size();
    for (int j = size - 1; j >= 0; --j)
    {
      directions.push_back((directions[j] + 1) % 4);
    }
  }

  // 드래곤 커브 격자 표시
  grid[y][x] = true;
  for (int dir : directions)
  {
    x += dx[dir];
    y += dy[dir];
    grid[y][x] = true;
  }
}

int countSquares()
{
  int count = 0;
  for (int y = 0; y < MAX - 1; ++y)
  {
    for (int x = 0; x < MAX - 1; ++x)
    {
      if (grid[y][x] && grid[y + 1][x] && grid[y][x + 1] && grid[y + 1][x + 1])
      {
        ++count;
      }
    }
  }
  return count;
}

int main()
{
  int n;
  cin >> n;

  while (n--)
  {
    int x, y, d, g;
    cin >> x >> y >> d >> g;
    drawDragonCurve(x, y, d, g);
  }

  cout << countSquares() << endl;
  return 0;
}
