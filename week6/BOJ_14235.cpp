#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<int> gifts;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        if (a == 0) {
            // 아이들을 만난 경우 가장 큰 선물의 가치 출력
            if (gifts.empty()) {
                cout << -1 << "\n"; // 선물이 없음
            } else {
                cout << gifts.top() << endl; // 가장 큰 선물의 가치 출력
                gifts.pop(); // 선물 제거
            }
        } else {
            // 선물 충전
            for (int j = 0; j < a; j++) {
                int value;
                cin >> value;
                gifts.push(value); // 선물 추가
            }
        }
    }

    return 0;
}
