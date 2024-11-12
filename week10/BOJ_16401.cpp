#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N;
    cin >> M >> N;

    vector<int> snacks(N);
    int max_length = 0;

    for (int i = 0; i < N; i++) {
        cin >> snacks[i];
        if (snacks[i] > max_length) {
            max_length = snacks[i];
        }
    }

    int left = 1, right = max_length;
    int result = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        long long count = 0;

        for (int i = 0; i < N; i++) {
            count += snacks[i] / mid;
        }

        if (count >= M) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << result << endl;
    return 0;
}
