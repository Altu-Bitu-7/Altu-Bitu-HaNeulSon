#include <iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	int cnt = 0;
	int num = 666;
	while (1) {
		int temp = num;
		while (temp != 0) {
			if (temp % 1000 == 666) {
				cnt++;
				break;
			}
			else {
				temp = temp / 10;
			}
		}
		if (cnt == N) {
			break;
		}
		num++;
	}
	cout << num;
	return 0;
}