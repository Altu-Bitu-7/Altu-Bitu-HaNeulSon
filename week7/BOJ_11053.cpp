#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n; 

    int A[1001]; 
    int dp[1001]; // LIS 길이

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < n; i++) {
        dp[i] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (A[i] > A[j]) { // 증가하는 부분 수열을 찾았을 때
                dp[i] = max(dp[i], dp[j] + 1); // 더 긴 수열로 갱신
            }
        }
    }

    // dp 배열에서 가장 큰 값을 찾으면 그 값이 LIS의 길이
    int result = *max_element(dp, dp + n);
    cout << result << "\n";

}
