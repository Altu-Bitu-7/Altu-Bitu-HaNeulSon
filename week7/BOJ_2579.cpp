#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int score[301] = {0}; // 계단 점
    int dp[301] = {0};    // 각 계단까지의 최댓값

    for (int i = 1; i <= n; i++) {
        cin >> score[i];
    }

    dp[1] = score[1];
    if (n > 1) {
        dp[2] = score[1] + score[2]; 
    }

    // 점화식
    for (int i = 3; i <= n; i++) {
        dp[i] = max(dp[i - 2], dp[i - 3] + score[i - 1]) + score[i];
    }

    cout << dp[n] << endl;

    return 0;
}
