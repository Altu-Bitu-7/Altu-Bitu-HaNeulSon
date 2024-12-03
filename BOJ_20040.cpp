#include <iostream>
#include <vector>
using namespace std;

int findParent(vector<int> &parent, int x)
{
  if (parent[x] != x)
  {
    parent[x] = findParent(parent, parent[x]);
  }
  return parent[x];
}

bool unionNodes(vector<int> &parent, vector<int> &rank, int a, int b)
{
  int rootA = findParent(parent, a);
  int rootB = findParent(parent, b);

  if (rootA == rootB)
    return true;

  if (rank[rootA] > rank[rootB])
  {
    parent[rootB] = rootA;
  }
  else if (rank[rootA] < rank[rootB])
  {
    parent[rootA] = rootB;
  }
  else
  {
    parent[rootB] = rootA;
    rank[rootA]++;
  }
  return false;
}

int main()
{
  int n, m;
  cin >> n >> m;

  vector<int> parent(n);
  vector<int> rank(n, 0);

  // 초기화
  for (int i = 0; i < n; i++)
  {
    parent[i] = i;
  }

  int result = 0;

  for (int i = 1; i <= m; i++)
  {
    int a, b;
    cin >> a >> b;

    if (unionNodes(parent, rank, a, b))
    {
      result = i; // 사이클이 처음으로 발생한 차례
      break;
    }
  }

  cout << result << endl;
  return 0;
}
