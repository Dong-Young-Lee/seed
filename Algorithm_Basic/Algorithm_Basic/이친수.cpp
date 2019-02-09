// ���繮�� : ������ �ý�

/*
n�ڸ� ��ģ���� ������ ���� ��, n-1�ڸ� ��ģ���� ������ �̿��Ѵ�.
����, ������ �ڸ��� �����Ѵ�.

n�ڸ� ��ģ���� ������ ���� ��, n-1�ڸ� ��ģ���� ������ �ڸ��� �� ������ �� ���� ���Ѵ�.
�׷��Ƿ� d�� ������ ���� �����Ѵ�.

d[n][last] : ������ �ڸ��� last�� n�ڸ� ��ģ���� ����
last�� ������ ( 0 <= last <= 2 )�̸�, 
last�� 2�� ��, d[n][2]�� n�ڸ� ��ģ���� �����̴�.
���� d[n][2] = d[n][0] + d[n][1]�̴�.

last 2�� ���� ���ϱ� ���� subproblem�� Ǫ�� ����� ������ ����.

d[n][0] = d[n-1][0] + d[n-1][1]
d[n][1] = d[n-1][0]

<���� 1> : ��ģ���� 0���� �������� �ʴ´�.
>> d[1][0] = 0
d[1][1] = 1
d[1][2] = 1
*/

// bottom-up
//#include <iostream>
//#include <vector>
//using namespace std;
//
//vector< vector<long long> > d(91, vector<long long>(3, -1));
//
//int main(void) {
//	int n;
//	cin >> n;
//
//	// 1. �ʱⰪ ����
//	d[1][0] = 0, d[1][1] = 1, d[1][2] = 1;
//
//	// 2. subproblem
//	for (int i = 2; i <= n; i++) {
//		d[i][0] = d[i - 1][0] + d[i - 1][1];
//		d[i][1] = d[i - 1][0];
//		d[i][2] = d[i][0] + d[i][1];
//	}
//
//	// 3. problem
//	cout << d[n][2];
//	return 0;
//}

// top-down
#include <iostream>
#include <vector>
using namespace std;

vector< vector<long long> > d(91, vector<long long>(3, -1));

long long solve(int n, int last) {
	// 2. �ʱⰪ ��ȯ
	if (n == 1) return d[n][last];

	// 3. �ذ� ����Ǿ� ������ ��ȯ
	if (d[n][last] != -1) return d[n][last];

	// 4. subproblem
	d[n][0] = solve(n - 1, 0) + solve(n - 1, 1);
	d[n][1] = solve(n - 1, 0);

	// 5. problem
	d[n][2] = d[n][0] + d[n][1];

	return d[n][last];
}

int main(void) {
	int n;
	cin >> n;

	// 1. �ʱⰪ ����
	d[1][0] = 0, d[1][1] = 1, d[1][2] = 1;

	cout << solve(n, 2);
	return 0;
}