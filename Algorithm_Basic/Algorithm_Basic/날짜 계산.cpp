/*

< Brute Force >
��� ����� �� �� �غ���

< Time Complexity >
n = 7980
O(n)

*/

// �ٸ� ��� : �ҽ� �ڵ� ����

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