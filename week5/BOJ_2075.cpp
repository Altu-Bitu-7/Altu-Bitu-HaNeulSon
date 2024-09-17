#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N;
    cin >> N;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int num;
            cin >> num;
            
            // 힙에 N개가 되기 전까지는 삽입
            if (minHeap.size() < N) {
                minHeap.push(num);
            } else {
                // N개 이상; 새로운 수가 힙의 최소값보다 크면 교체
                if (num > minHeap.top()) {
                    minHeap.pop();
                    minHeap.push(num);
                }
            }
        }
    }
    
    // 이미 더 작은 N-1개를 pop()했으니 top()이 N번째 수
    cout << minHeap.top() << endl;
    return 0;
}
