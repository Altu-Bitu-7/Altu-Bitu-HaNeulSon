#include <iostream>
using namespace std;

int dx[] = { 0, 0, -1, 1, -1, -1, 1, 1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
string directions[] = { "T", "B", "L", "R", "LT", "LB", "RT", "RB" };

bool isValid(int x, int y) {
    // 체스판 내에 있는가
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

int findDirectionIndex(string dir) {
    // 이동 확인
    for (int i = 0; i < 8; i++) {
        if (directions[i] == dir) return i;
    }
    return -1; // 유효하지 않은 방향은 존재하지 않음
}

int main() {
    string kingPos, stonePos;
    int n;
    cin >> kingPos >> stonePos >> n;

    // 킹과 돌의 위치를 숫자 좌표로 변환
    // 1도 string을 받았음을 주의
    int kingX = kingPos[0] - 'A', kingY = kingPos[1] - '1';
    int stoneX = stonePos[0] - 'A', stoneY = stonePos[1] - '1';

    for (int i = 0; i < n; i++) {
        string move;
        cin >> move;

        int dirIdx = findDirectionIndex(move); // 방향 인덱스

        int newKingX = kingX + dx[dirIdx];
        int newKingY = kingY + dy[dirIdx];

        if (!isValid(newKingX, newKingY)) continue;
        if (newKingX == stoneX && newKingY == stoneY) {
            // 킹이 돌과 같은 위치로 이동하려는 경우
            int newStoneX = stoneX + dx[dirIdx];
            int newStoneY = stoneY + dy[dirIdx];

            // 돌도 체스판 내에 있어야 이동
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

    // 숫자 좌표를 체스판 좌표로 변환하여 출력
    cout << char(kingX + 'A') << char(kingY + '1') << endl;
    cout << char(stoneX + 'A') << char(stoneY + '1') << endl;

    return 0;
}
