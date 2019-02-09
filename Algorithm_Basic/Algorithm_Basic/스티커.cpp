/*
������ ������ ������ ������ ����� �ȴ�.
* DP������ ���Ʈ������ Ǯ �� �ִ�.
* ���Ʈ������ ��� ����� ���� ���� ��

*�߿�* �� ������ DP������ ����?
...

���� 2������ �����Ǿ� �ְ�, ���� �������̴�
1������ n������ dp�� ä�������� �ȴ�.

�� ������ �������� �� 3���� �ִ�.

 0. ���� �ʴ´�.
 1. ���� ��ƼĿ�� ��´�.
 2. �Ʒ��� ��ƼĿ�� ��´�.

 �� �������� �� ���� ���� ���ÿ� ������ �޴´�.
 
 d[n][last] : ������ ������ last�� n������ �� ��ƼĿ 
 stk[i][j] : ��ƼĿ�� ����
 
 d[n][0] = max(d[n-1][0], d[n-1][1], d[n-1][2])
 d[n][1] = max(d[n-1][0], d[n-1][2]) + stk[0][n]
 d[n][2] = max(d[n-1][0], d[n-1][1]) + stk[1][n]

 ���� subproblem�� Ǯ�� problem�� ���ϰ� 
 �������� �ִ��� �����ش�.
 ans = max(d[n][0], d[n][1], d[n][2])

 < �߿� >
 �߿��� �� �� ������ dp�������� �ľ��ϴ� ���̰�,
 d�� ���ϰ�, ���ϴ� ����� �߿��ϴ�.
 ���⼭�� �������� �Ͱ� �������� ���� �˰� ������ ������ ����.
*/

// bottom-up
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector< vector<int> > d(100001, vector<int>(3, -1));
vector< vector<int> > stk(2, vector<int>(100001, 0));

int main(void) {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> stk[0][i];
		}
		for (int i = 1; i <= n; i++) {
			cin >> stk[1][i];
		}

		// 1. �ʱⰪ ����
		d[1][0] = 0, d[1][1] = stk[0][1], d[1][2] = stk[1][1];

		// 2. dp
		for (int i = 2; i <= n; i++) {
			d[i][0] = max(max(d[i - 1][0], d[i - 1][1]), d[i - 1][2]);
			d[i][1] = max(d[i - 1][0], d[i - 1][2]) + stk[0][i];
			d[i][2] = max(d[i - 1][0], d[i - 1][1]) + stk[1][i];
		}

		// 3. ������ ���ϱ�
		cout << max(max(d[n][0], d[n][1]), d[n][2]) << '\n';

	}

	return 0;
}

// top-down
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector< vector<int> > d(100001, vector<int>(4, -1));
vector< vector<int> > stk(2, vector<int>(100001, 0));

int solve(int n, int last) {
	// 2. �ʱⰪ ����
	if (n == 1) return d[n][last];

	// 3. �ذ� ����Ǿ� ������ ����
	if (d[n][last] != -1) return d[n][last];

	// 4. dp
	d[n][0] = max(max(solve(n - 1, 0), solve(n - 1, 1)), solve(n - 1, 2));
	d[n][1] = max(solve(n - 1, 0), solve(n - 1, 2)) + stk[0][n];
	d[n][2] = max(solve(n - 1, 0), solve(n - 1, 1)) + stk[1][n];

	// 5. ���� �� ���ϱ�
	d[n][3] = max(max(d[n][0], d[n][1]), d[n][2]);

	return d[n][last];
}

int main(void) {
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		// �׽�Ʈ ���̽� �ʱ�ȭ
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= 3; j++) {
				d[i][j] = -1;
			}
		}

		for (int i = 1; i <= n; i++) {
			cin >> stk[0][i];
		}
		for (int i = 1; i <= n; i++) {
			cin >> stk[1][i];
		}

		// 1. �ʱⰪ ����
		d[1][0] = 0, d[1][1] = stk[0][1], d[1][2] = stk[1][1];

		cout << solve(n, 3) << '\n';

	}
	return 0;
}