#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    int N, d, k, c;
    cin >> N >> d >> k >> c;
    
    vector<int> belt(N);
    for (int i = 0; i < N; i++) {
        cin >> belt[i];
    }

    unordered_map<int, int> sushi_count;
    int unique_sushi = 0;
    
    for (int i = 0; i < k; i++) {
        if (sushi_count[belt[i]] == 0) unique_sushi++;
        sushi_count[belt[i]]++;
    }
    
    int max_sushi = unique_sushi;
    if (sushi_count[c] == 0) max_sushi++;

    // 슬라이딩 윈도우
    for (int i = 0; i < N; i++) {
    
        int remove_sushi = belt[i];
        sushi_count[remove_sushi]--;
        if (sushi_count[remove_sushi] == 0) unique_sushi--;
        
        int add_sushi = belt[(i + k) % N];
        if (sushi_count[add_sushi] == 0) unique_sushi++;
        sushi_count[add_sushi]++;
        
        int current_sushi_count = unique_sushi;
        if (sushi_count[c] == 0) current_sushi_count++;
        max_sushi = max(max_sushi, current_sushi_count);
    }

    cout << max_sushi << endl;
    return 0;
}
