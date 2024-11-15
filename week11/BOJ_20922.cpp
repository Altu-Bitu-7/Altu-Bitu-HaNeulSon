#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> sequence(N);
    for (int i = 0; i < N; i++) {
        cin >> sequence[i];
    }

    unordered_map<int, int> count_map;
    int left = 0, max_length = 0;

    for (int right = 0; right < N; right++) {
        count_map[sequence[right]]++;

        while (count_map[sequence[right]] > K) {
            count_map[sequence[left]]--;
            if (count_map[sequence[left]] == 0) {
                count_map.erase(sequence[left]);
            }
            left++;
        }

        // 윈도우 길이 갱신
        max_length = max(max_length, right - left + 1);
    }

    cout << max_length << endl;
    return 0;
}
