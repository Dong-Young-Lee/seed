/*
���� Ž�� ����
dp�� Ǯ �� �ִ°�?
yes, �ֳ��ϸ� problem�� ���� ã�� �� subproblem�� ���� �����ϹǷ� ����
�� ������ ���� ����ϸ� �Ǳ� �����̴�.

d[n] ����
n�� ° ������ �κм����� �ִ� ����

< d[n] ���ϴ� ��� >
seq[n] : ������ n��° ��

d[1] = 1

���� seq���� �� ������ �� ���� ������ ���� �� �κ� ������ �����Ѵ�.
�׷��� ���ؼ� d[n]�� ���� ��, seq[n-1]���� seq[1]���� �����ϸ�
seq[n]���� ������ Ȯ���Ѵ�.
���࿡ �۴ٸ� d[n] = d[n-m] + 1 �� �Ͽ� �����ش�.

�����ش� max(d) �̴�.
*/

// bottom-up
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//vector<int> d(1001, -1);
//vector<int> seq(1001, -1);
//
//int main(void) {
//	int n;
//	cin >> n;
//
//	for (int i = 1; i <= n; i++) {
//		cin >> seq[i];
//	}
//
//	// 1. �ʱⰪ ����
//	d[1] = 1;
//
//	// 2. dq
//	for (int i = 1; i <= n; i++) {
//		d[i] = 1;
//		for (int j = 1; j < i; j++) {
//			if (seq[i] > seq[j] && d[i] <= d[j]) {
//				d[i] = d[j] + 1;
//			}
//		}
//	}
//
//	// 3. ���� �� �߿� �ִ밪�� ã�´�.
//	cout << *max_element(d.begin(), d.end());
//	
//	return 0;
//}

// ����, �ٽ� �õ�

// top-down
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//vector<int> d(1001, -1);
//vector<int> seq(1001, -1);
//
//int solve(int n) {
//	// 2. �ʱⰪ ��ȯ
//	if (n == 1)return d[1];
//
//	// 3. �ذ� ����Ǿ� ������ ��ȯ
//	if (d[n] != -1) return d[n];
//
//	// 4. subproblem
//	for (int i = 1; i < n; i++) {
//
//		if (seq[n] > seq[i] && d[n] < solve(i) + 1) {
//			d[n] = solve(i) + 1;
//		}
//	}
//
//	return d[n];
//}
//
//int main(void) {
//	int n;
//	cin >> n;
//
//	for (int i = 1; i <= n; i++) {
//		cin >> seq[i];
//	}
//
//	// 1. �ʱⰪ ����
//	d[1] = 1;
//
//	// dp
//	solve(n);
//
//	int ans = *max_element(d.begin(), d.end());
//
//	cout << ans;
//
//	return 0;
//}