#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N;
    unordered_set<int> cards;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        cards.insert(num);
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        int query;
        cin >> query;

        if (cards.find(query) != cards.end()) {
            cout << "1 ";
        } else {
            cout << "0 ";
        }
    }
    
    return 0;
}
