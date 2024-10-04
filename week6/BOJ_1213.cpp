#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    string name;
    cin >> name;

    map<char, int> freq;
    for (char c : name) {
        freq[c]++;
    }

    // 홀수 개수 문자의 카운트
    int oddCount = 0;
    char oddChar = 0;

    for (auto &p : freq) {
        if (p.second % 2 == 1) {
            oddCount++;
            oddChar = p.first;
        }
    }

    // 홀수 개수가 2개 이상이면 팰린드롬 불가능
    if (oddCount > 1) {
        cout << "I'm Sorry Hansoo" << endl;
        return 0;
    }

    string half = "", palindrome = "";

    // 팰린드롬 반쪽 구성
    for (auto &p : freq) {
        half += string(p.second / 2, p.first);
    }

    // 사전순으로 정렬
    sort(half.begin(), half.end());

    palindrome = half;

    // 홀수 문자가 있을 때 중앙에 추가
    if (oddCount == 1) {
        palindrome += oddChar;
    }

    // 반대편 추가하여 팰린드롬 완성
    reverse(half.begin(), half.end());
    palindrome += half;

    cout << palindrome << endl;

    return 0;
}
