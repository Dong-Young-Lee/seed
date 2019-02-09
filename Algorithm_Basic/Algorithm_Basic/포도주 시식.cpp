// ���繮�� : ��ģ��

/*
d[n] : n��° �ٱ��� �����ִ� �����ָ� ���� �ִ뷮
grape[n] : n��° ���� �������� ��

<���� 1> : �������� ���� �ִ� 3���� ��� ���� ���� ����.
���⼭ '����'�̶�� ������ Ȯ�� �Ϸ���
d[n][t] : ������ n��° �ٱ��� �������� t��ŭ ���� �����ָ� ���� �ִ뷮
t�� ���� : ( 0 <= t <= 2 )


n-1��° ���� ���� �ִ뷮���� n��°�� ������ 2������ �ִ�.
1. ������ �ʴ´�.
2. ���Ŵ�.

���⼭ <���� 1>�� ����Ͽ� ��ȭ���� ���ϸ�
1. ������ �ʴ´�.
d[i][0] = max(d[i - 1][0], d[i - 1][1], d[i - 1][2])

2. ���Ŵ�. t�� ���ô� �� ������ �����ؼ� ���� Ƚ��
d[i][1] = d[i - 1][0] + grape[i]
d[i][2] = d[i - 1][1] + grape[i]

���������� ������ ans�� max(d[n][0], d[n][1], d[n][2]) �̴�.
*/

// bottom-up
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//vector< vector<int> > d(10001, vector<int>(3, -1));
//vector<int> grape(10001, -1);
//
//int main(void) {
//	int n;
//	cin >> n;
//
//	for (int i = 1; i <= n; i++) {
//		cin >> grape[i];
//	}
//
//	// 1. �ʱⰪ ����
//	d[1][0] = 0, d[1][1] = grape[1], d[1][2] = grape[1];
//
//	// 2. dp
//	for (int i = 2; i <= n; i++) {
//		d[i][0] = max(max(d[i - 1][0], d[i - 1][1]), d[i - 1][2]);
//		d[i][1] = d[i - 1][0] + grape[i];
//		d[i][2] = d[i - 1][1] + grape[i];
//	}
//
//	// 3. ������ ���ϱ�
//	cout << max(max(d[n][0], d[n][1]), d[n][2]);
//
//	return 0;
//}

// Ʋ�� >> ������ �𸣰���. ���߿� �ٽ�

// top-down
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector< vector<int> > d(10001, vector<int>(4, -1));
vector<int> grape(10001, -1);

int solve(int n, int last) {
	// 3. �ʱⰪ ��ȯ
	if (n == 1)return d[n][last];

	// 4. �ذ� ����Ǿ� ������ ��ȯ
	if (d[n][last] != -1) return d[n][last];

	// 5. subproblem
	d[n][0] = max(max(solve(n - 1, 0), solve(n - 1, 1)), solve(n - 1, 2));
	d[n][1] = solve(n - 1, 0) + grape[n];
	d[n][2] = solve(n - 1, 1) + grape[n];

	// 6. �ִ� ���ϱ�
	d[n][3] = max(max(d[n][0], d[n][1]), d[n][2]);

	return d[n][last];
}

int main(void) {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> grape[i];
	}

	// 1. �ʱⰪ ����
	d[1][0] = 0;
	d[1][1] = grape[1];
	d[1][2] = grape[1];

	// 2. dp
	cout << solve(n, 3);

	return 0;
}