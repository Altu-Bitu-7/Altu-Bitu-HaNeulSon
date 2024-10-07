#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> graph(n + 1); 
    vector<bool> visited(n + 1, false); // 방문 여부
    
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    // BFS
    queue<int> q;
    q.push(1); 
    visited[1] = true;
    
    int infected_count = 0; 
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        for (int next : graph[current]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
                infected_count++;
            }
        }
    }
    
    cout << infected_count << endl;

    return 0;
}
