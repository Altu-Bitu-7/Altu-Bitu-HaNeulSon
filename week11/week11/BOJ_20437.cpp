#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        string W;
        int K;
        cin >> W >> K;

        vector<int> positions[26];
        int min_len = 10001, max_len = -1;

        for (int i = 0; i < W.size(); i++) {
            positions[W[i] - 'a'].push_back(i);
        }

        for (int i = 0; i < 26; i++) {
            if (positions[i].size() < K) continue; 
            
            for (int j = 0; j <= positions[i].size() - K; j++) {
                int length = positions[i][j + K - 1] - positions[i][j] + 1;
                min_len = min(min_len, length);
                max_len = max(max_len, length);
            }
        }

        if (min_len == 10001 || max_len == -1)
            cout << -1 << endl;
        else
            cout << min_len << " " << max_len << endl;
    }

    return 0;
}
