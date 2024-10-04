#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 톱니바퀴를 회전시키는 함수
void rotateGear(string &gear, int direction) {
    if (direction == 1) { // 시계 방향 회전
        char last = gear.back();
        gear.pop_back();
        gear.insert(gear.begin(), last);
    } else if (direction == -1) { // 반시계 방향 회전
        char first = gear.front();
        gear.erase(gear.begin());
        gear.push_back(first);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; // 톱니바퀴의 개수
    cin >> T;

    vector<string> gears(T); // 톱니바퀴 상태 저장
    for (int i = 0; i < T; i++) {
        cin >> gears[i];
    }

    int K; // 회전 횟수
    cin >> K;

    while (K--) {
        int num, dir;
        cin >> num >> dir;
        num--; // 인덱스는 0부터 시작하므로 1 감소

        vector<int> rotateDirs(T, 0); // 각 톱니바퀴의 회전 방향 저장
        rotateDirs[num] = dir;

        // 왼쪽으로 회전 영향 전파
        for (int i = num - 1; i >= 0; i--) {
            // 오른쪽 톱니바퀴의 6번 인덱스와 왼쪽 톱니바퀴의 2번 인덱스 비교
            if (gears[i][2] != gears[i + 1][6]) {
                rotateDirs[i] = -rotateDirs[i + 1];
            } else {
                break; // 극이 같으면 회전하지 않으므로 중단
            }
        }

        // 오른쪽으로 회전 영향 전파
        for (int i = num + 1; i < T; i++) {
            // 왼쪽 톱니바퀴의 2번 인덱스와 오른쪽 톱니바퀴의 6번 인덱스 비교
            if (gears[i - 1][2] != gears[i][6]) {
                rotateDirs[i] = -rotateDirs[i - 1];
            } else {
                break; // 극이 같으면 회전하지 않으므로 중단
            }
        }

        // 회전 적용
        for (int i = 0; i < T; i++) {
            if (rotateDirs[i] != 0) {
                rotateGear(gears[i], rotateDirs[i]);
            }
        }
    }

    // 12시 방향이 S극인 톱니바퀴의 개수 계산
    int count = 0;
    for (int i = 0; i < T; i++) {
        if (gears[i][0] == '1') {
            count++;
        }
    }

    cout << count << '\n';

    return 0;
}
