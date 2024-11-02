#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int left = 1, right = N;
    int answer = N;
    
    vector<int> lights(M);
    for (int i = 0; i < M; i++) {
        cin >> lights[i];
    }

    
    sort(lights.begin(), lights.end());

    while (left <= right) {
        int mid = (left + right) / 2;
        int last_position = 0;

        bool can_light = true;
        for (int i = 0; i < M; i++) {
            if (lights[i] - mid > last_position) {
                can_light = false;
                break;
            }
            last_position = lights[i] + mid;
        }

        if (can_light && last_position >= N) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << answer << endl;
    return 0;
}
