#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N;
    
    vector<int> passengers(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        cin >> passengers[i];
    }
    
    cin >> M;

    vector<int> prefixSum(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        prefixSum[i] = prefixSum[i - 1] + passengers[i];
    }

    vector<int> dp(N + 1, 0);  // 소형 기관차 1대가 끌 수 있는 최대 손님 수
    vector<int> dp2(N + 1, 0); // 소형 기관차 2대가 끌 수 있는 최대 손님 수
    vector<int> dp3(N + 1, 0); // 소형 기관차 3대가 끌 수 있는 최대 손님 수

    // 소형 기관차 1대의 최대 수용 인원
    for (int i = M; i <= N; ++i) {
        dp[i] = max(dp[i - 1], prefixSum[i] - prefixSum[i - M]);
    }

    // 소형 기관차 2대의 최대 수용 인원
    for (int i = 2 * M; i <= N; ++i) {
        dp2[i] = max(dp2[i - 1], dp[i - M] + (prefixSum[i] - prefixSum[i - M]));
    }

    // 소형 기관차 3대의 최대 수용 인원
    for (int i = 3 * M; i <= N; ++i) {
        dp3[i] = max(dp3[i - 1], dp2[i - M] + (prefixSum[i] - prefixSum[i - M]));
    }
    
    cout << dp3[N] << endl;

    return 0;
}
