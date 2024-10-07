#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n; // 전체 사람
    cin >> n;
    
    int person1, person2;
    cin >> person1 >> person2;
    
    int m; // 부모 자식 관계의 수
    cin >> m;
    
    vector<vector<int>> graph(n + 1); // 그래프, 인덱스는 사람 번호로 사용
    vector<int> visited(n + 1, -1); // 방문 여부 및 촌수를 기록 (-1은 미방문)
    
    for (int i = 0; i < m; ++i) {
        int parent, child;
        cin >> parent >> child;
        graph[parent].push_back(child);
        graph[child].push_back(parent); 
    }
    
    // BFS
    queue<int> q;
    q.push(person1); 
    visited[person1] = 0; 
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        for (int next : graph[current]) {
            if (visited[next] == -1) { 
                visited[next] = visited[current] + 1; 
                q.push(next);
            }
        }
    }
    
    if (visited[person2] == -1) {
        cout << -1 << "\n"; // 연결되지 않은 경우
    } else {
        cout << visited[person2] << "\n";
    }

    return 0;
}
