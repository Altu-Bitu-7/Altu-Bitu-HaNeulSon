#include <iostream>
using namespace std;

int dx[] = { 0, 0, -1, 1, -1, -1, 1, 1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
string directions[] = { "T", "B", "L", "R", "LT", "LB", "RT", "RB" };

bool isValid(int x, int y) {
    // ü���� ���� �ִ°�
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

int findDirectionIndex(string dir) {
    // �̵� Ȯ��
    for (int i = 0; i < 8; i++) {
        if (directions[i] == dir) return i;
    }
    return -1; // ��ȿ���� ���� ������ �������� ����
}

int main() {
    string kingPos, stonePos;
    int n;
    cin >> kingPos >> stonePos >> n;

    // ŷ�� ���� ��ġ�� ���� ��ǥ�� ��ȯ
    // 1�� string�� �޾����� ����
    int kingX = kingPos[0] - 'A', kingY = kingPos[1] - '1';
    int stoneX = stonePos[0] - 'A', stoneY = stonePos[1] - '1';

    for (int i = 0; i < n; i++) {
        string move;
        cin >> move;

        int dirIdx = findDirectionIndex(move); // ���� �ε���

        int newKingX = kingX + dx[dirIdx];
        int newKingY = kingY + dy[dirIdx];

        if (!isValid(newKingX, newKingY)) continue;
        if (newKingX == stoneX && newKingY == stoneY) {
            // ŷ�� ���� ���� ��ġ�� �̵��Ϸ��� ���
            int newStoneX = stoneX + dx[dirIdx];
            int newStoneY = stoneY + dy[dirIdx];

            // ���� ü���� ���� �־�� �̵�
            if (!isValid(newStoneX, newStoneY)) continue;

            kingX = newKingX;
            kingY = newKingY;
            stoneX = newStoneX;
            stoneY = newStoneY;
        }
        else {
            kingX = newKingX;
            kingY = newKingY;
        }
    }

    // ���� ��ǥ�� ü���� ��ǥ�� ��ȯ�Ͽ� ���
    cout << char(kingX + 'A') << char(kingY + '1') << endl;
    cout << char(stoneX + 'A') << char(stoneY + '1') << endl;

    return 0;
}
