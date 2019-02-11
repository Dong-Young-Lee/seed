/*

< recursive function >

1. �Ұ����� ���
2. ������ ã�� ���
3. ���� ��� ȣ��

*/

#include <iostream>
using namespace std;

int solve(int n, int sum) {
	if (sum > n) return 0;
	if (sum == n) return 1;
	int count = 0; // ���⼭ ����! �߿�!

	for (int i = 1; i <= 3; i++) {
		count += solve(n, sum + i);
	}

	return count; // ��Ƽ� �÷� ����!
}

int main(void) {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		int sum = 0;
		cout << solve(n, sum) << '\n';
	}

	return 0;
}