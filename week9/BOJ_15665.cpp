#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int N, M;
vector<int> numbers;
vector<int> selected;

void dfs(int depth) {
    if (depth == M) {
        for (int num : selected) {
            cout << num << ' ';
        }
        cout << '\n';
        return;
    }
    
    for (int i = 0; i < N; i++) {
        selected.push_back(numbers[i]);
        dfs(depth + 1);
        selected.pop_back();
    }
}

int main() {
    cin >> N >> M;
    set<int> uniqueNumbers; // 중복 제거를 위해 set
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        uniqueNumbers.insert(num); // 중복 수 제거
    }

    numbers.assign(uniqueNumbers.begin(), uniqueNumbers.end());
    N = numbers.size(); 
    dfs(0);
    
    return 0;
}
