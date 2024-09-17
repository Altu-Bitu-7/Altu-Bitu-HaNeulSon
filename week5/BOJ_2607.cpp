#include <iostream>
#include <vector>

using namespace std;

int N;
string S;
vector<int> firstWordCnt;

vector<int> countFreq(string s) {
    vector<int> ret(26, 0);
    
    for (auto c: s) {
        ret[c-'A']++;
    }
    
    return ret;
}

bool check(string word) {
    vector<int> cnt = countFreq(word);
    vector<int> diff;
    
    for (int i=0; i<26; i++) {
        if (cnt[i] != firstWordCnt[i]) {
            diff.push_back(cnt[i] - firstWordCnt[i]);
        }
    }
    
    if (diff.empty()) return true;

    if (diff.size() == 1 && abs(diff[0]) == 1) return true;

    if (diff.size() == 2 && abs(diff[0]) == true && diff[0] + diff[1] == false) return true;
    
    return false;
}

int solution() {
    int ret = 0;
    
    firstWordCnt = countFreq(S);
    
    for (int i=0; i<N-1; i++) {
        string temp;
        cin >> temp;
        
        if (check(temp)) ret++;
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    cin >> S;

    cout << solution();
    
    return 0;
}