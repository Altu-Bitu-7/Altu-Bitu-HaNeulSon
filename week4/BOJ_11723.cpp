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
            bit |= (1 << x);  // x��° ��Ʈ�� 1�� ����
        }
        else if (cmd == "remove") {
            cin >> x;
            bit &= ~(1 << x);  // x��° ��Ʈ�� 0���� ����
        }
        else if (cmd == "check") {
            cin >> x;
            cout << ((bit & (1 << x)) ? 1 : 0) << '\n';  // x��° ��Ʈ�� 1�̸� 1, �ƴϸ� 0 ���
        }
        else if (cmd == "toggle") {
            cin >> x;
            bit ^= (1 << x);  // x��° ��Ʈ�� ������
        }
        else if (cmd == "all") {
            bit = (1 << 21) - 1;  // 1���� 20���� ��� ��Ʈ�� 1�� ���� (2^21 - 1)
        }
        else if (cmd == "empty") {
            bit = 0;  // ��� ��Ʈ�� 0���� ����
        }
    }

    return 0;
}
