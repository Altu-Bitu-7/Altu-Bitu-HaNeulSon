#include <iostream>
using namespace std;

int main() {
    int K; // 1m^2당 자라는 참외 개수
    cin >> K;

    int dir[6], len[6]; // 방향, 길이
    for (int i = 0; i < 6; i++) {
        cin >> dir[i] >> len[i];
    }

    int maxWidth = 0, maxHeight = 0;
    int maxWidthIndex = 0, maxHeightIndex = 0;

    // 가장 긴 가로, 세로
    for (int i = 0; i < 6; i++) {
        if (dir[i] == 1 || dir[i] == 2) { // 동/서
            if (len[i] > maxWidth) {
                maxWidth = len[i];
                maxWidthIndex = i;
            }
        } else if (dir[i] == 3 || dir[i] == 4) { // 남/북
            if (len[i] > maxHeight) {
                maxHeight = len[i];
                maxHeightIndex = i;
            }
        }
    }

    int smallWidth = len[(maxWidthIndex + 3) % 6];
    int smallHeight = len[(maxHeightIndex + 3) % 6];

    int area = (maxWidth * maxHeight) - (smallWidth * smallHeight);

    cout << area * K << endl;

    return 0;
}
