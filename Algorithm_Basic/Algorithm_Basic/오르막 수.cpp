/*
길이 n인 오르막 수의 개수를 구할 때, 길이 n-1인 오르막 수에서
마지막 자리가 0~9가 올 수 있다.
길이 n인 오르막 수의 마지막 자리와 길이 n-1인 오르막 수의 마지막 자리를 비교
따라서 d는 다음과 같이 정의한다.

d[n][last] : 마지막 자리가 last인 길이 n인 오르막 수의 개수
last의 범위는 ( 0 <= last <= 10 )이고,
last == 10 이면, 길이 n인 오르막 수의 개수이다.
따라서 d[n][10] = d[n][0] + ... + d[n][9] 이다.

d[n][10]을 구하기 위한 d[n][last] ( 0 <= last <= 9)를 구하는 방법은 다음과 같다.

d[n][0] = d[n-1][0]
d[n][1] = d[n-1][0] + d[n-1][1]
d[n][2] = d[n-1][0] + d[n-1][1] + d[n-1][2]
...
d[n][9] = d[n-1][0] + ... + d[n-1][9]
*/

// bottom-up
//#include <iostream>
//#include <vector>
//using namespace std;
//
//vector< vector<long long> > d(1001, vector<long long>(11, -1));
//const long long mod = 10007LL;
//
//int main(void) {
//	int n;
//	cin >> n;
//
//	// 1. 초기값 설정
//	for (int i = 0; i <= 9; i++) {
//		d[1][i] = 1;
//	}
//	d[1][10] = 10;
//
//	// 2. subproblem을 구하여 저장한다.
//	for (int i = 2; i <= n; i++) {
//		for (int j = 0; j <= 9; j++) {
//			d[i][j] = 0;
//			for (int k = 0; k <= j; k++) {
//				d[i][j] += (d[i - 1][k] % mod);
//			}
//			d[i][j] %= mod;
//		}
//	}
//
//	// 3. subproblem을 모두 더하여 해를 구한다.
//	d[n][10] = 0;
//	for (int i = 0; i <= 9; i++) {
//		d[n][10] += (d[n][i] % mod);
//	}
//	d[n][10] %= mod;
//
//	cout << d[n][10];
//
//	return 0;
//}

// top-down
#include <iostream>
#include <vector>
using namespace std;

vector< vector<long long> > d(1001, vector<long long>(11, -1));
const long long mod = 10007LL;

long long solve(int n, int last) {
	// 2. 초기값 리턴
	if (n == 1)return d[n][last];

	// 3. 해가 저장되어 있으면 리턴
	if (d[n][last] != -1) return d[n][last];

	// 4. subproblem
	for (int i = 0; i <= 9; i++) {
		d[n][i] = 0;
		for (int j = 0; j <= i; j++) {
			d[n][i] += solve(n - 1, j) % mod;
		}
	}

	// 5. problem
	d[n][10] = 0;
	for (int i = 0; i <= 9; i++) {
		d[n][10] += d[n][i] % mod;
	}
	d[n][10] %= mod;

	return d[n][last];
}

int main(void) {
	int n;
	cin >> n;

	// 1. 초기값 설정
	for (int i = 0; i <= 9; i++) {
		d[1][i] = 1;
	}
	d[1][10] = 10;

	cout << solve(n, 10);

	return 0;
}