#include <iostream>
#include <vector>
using namespace std;

int N, M;
int r, c, d;
vector<vector<int>> room;
vector<vector<bool>> cleaned;

// 북, 동, 남, 서 방향 설정 (d = 0, 1, 2, 3)
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

// 왼쪽으로 회전하는 함수
int turn_left(int direction) {
    return (direction + 3) % 4;
}

int main() {
    cin >> N >> M;
    cin >> r >> c >> d;
    
    room.assign(N, vector<int>(M));
    cleaned.assign(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> room[i][j];
        }
    }

    int cleaned_count = 0;
    
    while (true) {

      // 현재
        if (!cleaned[r][c]) {
            cleaned[r][c] = true;
            cleaned_count++;
        }

        bool moved = false;
        for (int i = 0; i < 4; i++) {
            // 좌측으로
            d = turn_left(d);
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (room[nr][nc] == 0 && !cleaned[nr][nc]) {
                r = nr;
                c = nc;
                moved = true;
                break;
            }
        }

        // 청소할 칸X
        if (!moved) {
            
            int back_direction = (d + 2) % 4;
            int nr = r + dr[back_direction];
            int nc = c + dc[back_direction];

            if (room[nr][nc] == 0) {
                r = nr;
                c = nc;
            } else { // 후진 불가
                break;
            }
        }
    }

    cout << cleaned_count << endl;
    return 0;
}
