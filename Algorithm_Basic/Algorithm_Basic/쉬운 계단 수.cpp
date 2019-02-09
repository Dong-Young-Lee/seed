/*
d[n] ���� : ���̰� n�� ��� ���� ����

< d[n] ���ϴ� ��� >

���� n ��� ���� ���� �� �������� ���� ���� ������ �д�.
�������� ���� ���� ���� n-1 ��� ���� ������ ���� ���Ͽ� ������ �� �̾�� �Ѵ�.
�������� ���� ���� Ȯ���ϱ� ���Ͽ� d�� 2���� �迭�� �����Ѵ�.

d[n][last] : ������ ���ڰ� last�� ���� n�� ��� ���� ����

d[n][10]�� ���� n�� ��� ���� �����̸�
d[n][10] = d[n][0] + d[n][2] + ... + d[n][9] �̴�.

�̴� ������ problem���� ���ϰ�, ���������� ���ؼ� �ظ� ���Ѵ�.

problem�� subproblem�� ���ϴ� ����� ���� ����� ������ ����.

<���� 1> n�� ��� ���� last�� 0�̸� ������ ���� 1���̴�.
d[n][0] = d[n-1][1]

<�Ϲ�> n�� ��� ���� last�� 1~8�̸� ������ ���� last-1, last+1�̴�.
d[n][1] = d[n-1][0] + d[n-1][2]
...
d[n][8] = d[n-1][7] + d[n-1][9]

<���� 2> n�� ��� ���� last�� 9�̸� ������ ���� 8���̴�.
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
//	// 1. �ʱⰪ ����
//	d[1][0] = 0;
//	for (int i = 1; i <= 9; i++) {
//		d[1][i] = 1;
//	}
//	d[1][10] = 9;
//
//	// 2. subproblem���� problem���� �ذ��ϸ� �����Ѵ�.
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
//		// 3. �ظ� ���ϱ� ���Ͽ� ���� ������ ��� ���ؾ� �Ѵ�.
//		d[i][10] = 0;
//		for (int k = 0; k <= 9; k++) {
//			d[i][10] += (d[i][k] % mod);
//		}
//		d[i][10] %= mod;
//	}
//
//	// 4. ���� �ظ� ����Ѵ�.
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
	// 2. �ʱⰪ ��ȯ
	if (n == 1) {
		return d[n][last];
	}

	// 3. �ذ� ����Ǿ� �ִٸ� ��ȯ
	if (d[n][last] != -1) {
		return d[n][last];
	}

	// 4. subproblem�� Ǯ�� �����Ѵ�.
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
	
	// 5. �ظ� ���ϱ� ���ؼ� ���� ������ ��� ���ϰ� �����Ѵ�.
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
	
	// 1. �ʱⰪ ����
	d[1][0] = 0;
	for (int i = 1; i <= 9; i++) {
		d[1][i] = 1;
	}
	d[1][10] = 9;
	
	cout << solve(n, 10);
	return 0;
}