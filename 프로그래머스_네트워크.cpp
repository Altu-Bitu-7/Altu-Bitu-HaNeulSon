#include <string>
#include <vector>

using namespace std;

void dfs(int node, vector<vector<int>> &computers, vector<bool> &visited)
{
  visited[node] = true;
  for (int i = 0; i < computers.size(); i++)
  {
    if (computers[node][i] == 1 && !visited[i])
    {
      dfs(i, computers, visited);
    }
  }
}

int solution(int n, vector<vector<int>> computers)
{
  vector<bool> visited(n, false);
  int networkCount = 0;

  for (int i = 0; i < n; i++)
  {
    if (!visited[i])
    {
      dfs(i, computers, visited);
      networkCount++;
    }
  }

  return networkCount;
}