#include <iostream>
#include <vector>

using namespace std;
const int MAX = 500 + 1;
bool graph[MAX][MAX];

int main()
{
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; ++i)
  {
    for (int j = 1; j <= n; ++j)
    {
      graph[i][j] = false;
    }
  }

  for (int i = 0; i < m; ++i)
  {
    int a, b;
    cin >> a >> b;
    graph[a][b] = true;
  }

  for (int k = 1; k <= n; ++k)
  {
    for (int i = 1; i <= n; ++i)
    {
      for (int j = 1; j <= n; ++j)
      {
        if (graph[i][k] && graph[k][j])
        {
          graph[i][j] = true;
        }
      }
    }
  }

  int result = 0;
  for (int i = 1; i <= n; ++i)
  {
    int count = 0;
    for (int j = 1; j <= n; ++j)
    {
      if (graph[i][j] || graph[j][i])
      {
        ++count;
      }
    }
    if (count == n - 1)
    {
      ++result;
    }
  }

  cout << result << endl;
  return 0;
}
