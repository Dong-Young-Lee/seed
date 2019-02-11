/*

< Brute Force >
모든 경우의 수 다 해보기

< Time Complexity >
n = 7980
O(n)

*/

// 다른 방법 : 소스 코드 참조

#include <iostream>
using namespace std;

int main(void) {
	int e, s, m;
	cin >> e >> s >> m;
	
	int ee = 1, ss = 1, mm = 1;
	int year = 1;
	
	while (1) {
		if (e == ee && s == ss && m == mm) {
			break;
		}

		year++;
		ee++, ss++, mm++;
		if (ee == 16) {
			ee = 1;
		}
		if (ss == 29) {
			ss = 1;
		}
		if (mm == 20) {
			mm = 1;
		}

	}
	cout << year;

	return 0;
}