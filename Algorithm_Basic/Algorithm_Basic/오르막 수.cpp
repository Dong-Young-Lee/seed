/*
���� n�� ������ ���� ������ ���� ��, ���� n-1�� ������ ������
������ �ڸ��� 0~9�� �� �� �ִ�.
���� n�� ������ ���� ������ �ڸ��� ���� n-1�� ������ ���� ������ �ڸ��� ��
���� d�� ������ ���� �����Ѵ�.

d[n][last] : ������ �ڸ��� last�� ���� n�� ������ ���� ����
last�� ������ ( 0 <= last <= 10 )�̰�,
last == 10 �̸�, ���� n�� ������ ���� �����̴�.
���� d[n][10] = d[n][0] + ... + d[n][9] �̴�.

d[n][10]�� ���ϱ� ���� d[n][last] ( 0 <= last <= 9)�� ���ϴ� ����� ������ ����.

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
//	// 1. �ʱⰪ ����
//	for (int i = 0; i <= 9; i++) {
//		d[1][i] = 1;
//	}
//	d[1][10] = 10;
//
//	// 2. subproblem�� ���Ͽ� �����Ѵ�.
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
//	// 3. subproblem�� ��� ���Ͽ� �ظ� ���Ѵ�.
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
	// 2. �ʱⰪ ����
	if (n == 1)return d[n][last];

	// 3. �ذ� ����Ǿ� ������ ����
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

	// 1. �ʱⰪ ����
	for (int i = 0; i <= 9; i++) {
		d[1][i] = 1;
	}
	d[1][10] = 10;

	cout << solve(n, 10);

	return 0;
}