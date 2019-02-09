/*
d[n] 정의 : 길이가 n인 계단 수의 개수

< d[n] 구하는 방법 >

길이 n 계단 수를 구할 때 마지막에 오는 수에 초점을 둔다.
마지막에 오는 수는 길이 n-1 계단 수의 마지막 수와 비교하여 인접한 수 이어야 한다.
마지막에 오는 수를 확인하기 위하여 d는 2차원 배열로 정의한다.

d[n][last] : 마지막 숫자가 last인 길이 n인 계단 수의 개수

d[n][10]은 길이 n인 계단 수의 개수이며
d[n][10] = d[n][0] + d[n][2] + ... + d[n][9] 이다.

이는 각각의 problem들을 구하고, 최종적으로 더해서 해를 구한다.

problem은 subproblem을 구하는 방법과 같고 방법은 다음과 같다.

<예외 1> n인 계단 수의 last가 0이면 인접한 수는 1뿐이다.
d[n][0] = d[n-1][1]

<일반> n인 계단 수의 last가 1~8이면 인접한 수는 last-1, last+1이다.
d[n][1] = d[n-1][0] + d[n-1][2]
...
d[n][8] = d[n-1][7] + d[n-1][9]

<예외 2> n인 계단 수의 last가 9이면 인접한 수는 8뿐이다.
d[n][9] = d[n-1][8]
*/

// bottom-up
//#include <iostream>
//#include <vector>
//using namespace std;
//
//vector< vector<long long> > d(101, vector<long long>(11, -1));
//const long long mod = 1000000000LL;
//
//int main(void) {
//	int n;
//	cin >> n;
//
//	// 1. 초기값 설정
//	d[1][0] = 0;
//	for (int i = 1; i <= 9; i++) {
//		d[1][i] = 1;
//	}
//	d[1][10] = 9;
//
//	// 2. subproblem부터 problem까지 해결하며 저장한다.
//	for (int i = 2; i <= n; i++) {
//		for (int j = 0; j <= 9; j++) {
//			if (j == 0) {
//				d[i][j] = (d[i - 1][j + 1] % mod);
//			}
//			if (j >= 1 && j <= 8) {
//				d[i][j] = (d[i - 1][j - 1] + d[i - 1][j + 1]) % mod;
//			}
//			if (j == 9) {
//				d[i][j] = (d[i - 1][j - 1]) % mod;
//			}
//		}
//
//		// 3. 해를 구하기 위하여 위의 값들을 모두 더해야 한다.
//		d[i][10] = 0;
//		for (int k = 0; k <= 9; k++) {
//			d[i][10] += (d[i][k] % mod);
//		}
//		d[i][10] %= mod;
//	}
//
//	// 4. 최종 해를 출력한다.
//	cout << d[n][10] << '\n';
//
//	return 0;
//}

// top-down
#include <iostream>
#include <vector>
using namespace std;

vector< vector<long long> > d(101, vector<long long>(11, -1));
const long long mod = 1000000000LL;

long long solve(int n, int last) {
	// 2. 초기값 반환
	if (n == 1) {
		return d[n][last];
	}

	// 3. 해가 저장되어 있다면 반환
	if (d[n][last] != -1) {
		return d[n][last];
	}

	// 4. subproblem을 풀고 저장한다.
	for (int i = 0; i <= 9; i++) {
		if (i == 0) {
			d[n][i] = solve(n - 1, i + 1) % mod;
		}
		if (i >= 1 && i <= 8) {
			d[n][i] = (solve(n - 1, i - 1) + solve(n - 1, i + 1)) % mod;
		}
		if (i == 9) {
			d[n][i] = solve(n - 1, i - 1) % mod;
		}
	}
	
	// 5. 해를 구하기 위해서 위의 값들을 모두 더하고 저장한다.
	d[n][10] = 0;
	for (int i = 0; i <= 9; i++) {
		d[n][10] += (d[n][i] % mod);
	}
	d[n][10] %= mod;
	
	return d[n][last];
}

int main(void) {
	int n;
	cin >> n;
	
	// 1. 초기값 설정
	d[1][0] = 0;
	for (int i = 1; i <= 9; i++) {
		d[1][i] = 1;
	}
	d[1][10] = 9;
	
	cout << solve(n, 10);
	return 0;
}