#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> numbers;
int ops[4]; // + - * /
int maxResult = -1e9, minResult = 1e9;

void dfs(int index, int currentResult) {
    if (index == N) {
        maxResult = max(maxResult, currentResult);
        minResult = min(minResult, currentResult);
        return;
    }
    
    if (ops[0] > 0) { // 덧셈
        ops[0]--;
        dfs(index + 1, currentResult + numbers[index]);
        ops[0]++;
    }
    
    if (ops[1] > 0) { // 뺄셈
        ops[1]--;
        dfs(index + 1, currentResult - numbers[index]);
        ops[1]++;
    }
    
    if (ops[2] > 0) { // 곱셈
        ops[2]--;
        dfs(index + 1, currentResult * numbers[index]);
        ops[2]++;
    }
    
    if (ops[3] > 0) { // 나눗셈
        ops[3]--;
        dfs(index + 1, currentResult / numbers[index]);
        ops[3]++;
    }
}

int main() {
    cin >> N;
    numbers.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> ops[i];
    }
    
    dfs(1, numbers[0]); // 첫 번째 수는 미리 넣어주고 시작
    cout << maxResult << '\n' << minResult << '\n';
    
    return 0;
}
