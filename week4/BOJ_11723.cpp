#include <iostream>

using namespace std;

int main() {

    int M;
    cin >> M;

    int bit = 0;
    string cmd;
    int x;

    while (M--) {
        cin >> cmd;

        if (cmd == "add") {
            cin >> x;
            bit |= (1 << x);  // x번째 비트를 1로 설정
        }
        else if (cmd == "remove") {
            cin >> x;
            bit &= ~(1 << x);  // x번째 비트를 0으로 설정
        }
        else if (cmd == "check") {
            cin >> x;
            cout << ((bit & (1 << x)) ? 1 : 0) << '\n';  // x번째 비트가 1이면 1, 아니면 0 출력
        }
        else if (cmd == "toggle") {
            cin >> x;
            bit ^= (1 << x);  // x번째 비트를 뒤집음
        }
        else if (cmd == "all") {
            bit = (1 << 21) - 1;  // 1부터 20까지 모든 비트를 1로 설정 (2^21 - 1)
        }
        else if (cmd == "empty") {
            bit = 0;  // 모든 비트를 0으로 설정
        }
    }

    return 0;
}
