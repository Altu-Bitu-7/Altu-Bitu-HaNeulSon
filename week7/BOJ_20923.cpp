#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M; // N: 카드 개수, M: 게임 진행 횟수
    cin >> N >> M;
    
    deque<int> dodo_deck, su_deck; // 도도와 수연의 덱
    deque<int> dodo_ground, su_ground; // 도도와 수연의 그라운드

    // 도도와 수연의 초기 덱 입력 (맨 아래 카드부터 입력됨)
    for (int i = 0; i < N; i++) {
        int d, s;
        cin >> d >> s;
        dodo_deck.push_back(d);
        su_deck.push_back(s);
    }

    bool game_over = false;
    for (int turn = 0; turn < M; turn++) {
        if (turn % 2 == 0) { // 도도의 턴
            int card = dodo_deck.front();
            dodo_deck.pop_front();
            dodo_ground.push_front(card);

            if (dodo_deck.empty()) {
                cout << "su" << '\n';
                game_over = true;
                break;
            }
        } else { // 수연의 턴
            int card = su_deck.front();
            su_deck.pop_front();
            su_ground.push_front(card);

            if (su_deck.empty()) {
                cout << "do" << '\n';
                game_over = true;
                break;
            }
        }

        // 종을 칠 수 있는지 확인
        bool bell_dodo = false, bell_su = false;
        if (!dodo_ground.empty() && dodo_ground.front() == 5) {
            bell_dodo = true;
        }
        if (!su_ground.empty() && su_ground.front() == 5) {
            bell_dodo = true;
        }
        if (!dodo_ground.empty() && !su_ground.empty()) {
            int sum = dodo_ground.front() + su_ground.front();
            if (sum == 5) {
                bell_su = true;
            }
        }

        // 종을 친 경우 처리
        if (bell_dodo) {
            // 도도가 종을 친 경우
            // 수연의 그라운드 카드부터 가져감
            while (!su_ground.empty()) {
                dodo_deck.push_back(su_ground.back());
                su_ground.pop_back();
            }
            while (!dodo_ground.empty()) {
                dodo_deck.push_back(dodo_ground.back());
                dodo_ground.pop_back();
            }
        } else if (bell_su) {
            // 수연이 종을 친 경우
            // 도도의 그라운드 카드부터 가져감
            while (!dodo_ground.empty()) {
                su_deck.push_back(dodo_ground.back());
                dodo_ground.pop_back();
            }
            while (!su_ground.empty()) {
                su_deck.push_back(su_ground.back());
                su_ground.pop_back();
            }
        }
    }

    if (!game_over) {
        if (dodo_deck.size() > su_deck.size()) {
            cout << "do" << '\n';
        } else if (dodo_deck.size() < su_deck.size()) {
            cout << "su" << '\n';
        } else {
            cout << "dosu" << '\n';
        }
    }

    return 0;
}
