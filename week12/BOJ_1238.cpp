#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

vector<int> dijkstra(int start, int n, const vector<vector<pair<int, int>>> &graph)
{
  vector<int> dist(n + 1, INF);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

  dist[start] = 0;
  pq.emplace(0, start);

  while (!pq.empty())
  {
    int current_dist = pq.top().first;
    int current_node = pq.top().second;
    pq.pop();

    if (current_dist > dist[current_node])
      continue;

    for (const auto &[next_node, weight] : graph[current_node])
    {
      int new_dist = current_dist + weight;
      if (new_dist < dist[next_node])
      {
        dist[next_node] = new_dist;
        pq.emplace(new_dist, next_node);
      }
    }
  }

  return dist;
}

int main()
{
  int n, m, x;
  cin >> n >> m >> x;

  vector<vector<pair<int, int>>> graph(n + 1);
  vector<vector<pair<int, int>>> reverse_graph(n + 1);

  for (int i = 0; i < m; ++i)
  {
    int u, v, t;
    cin >> u >> v >> t;
    graph[u].emplace_back(v, t);
    reverse_graph[v].emplace_back(u, t);
  }

  // X에서 다른 마을로 가는 최단 거리
  vector<int> dist_from_x = dijkstra(x, n, graph);

  // 다른 마을에서 X로 오는 최단 거리
  vector<int> dist_to_x = dijkstra(x, n, reverse_graph);

  // 왕복 시간 계산
  int max_time = 0;
  for (int i = 1; i <= n; ++i)
  {
    if (dist_from_x[i] != INF && dist_to_x[i] != INF)
    {
      max_time = max(max_time, dist_from_x[i] + dist_to_x[i]);
    }
  }

  cout << max_time << endl;
  return 0;
}
