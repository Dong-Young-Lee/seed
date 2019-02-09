#include <iostream>

// top-down
//
//long long d[1001] = { 0 };
//
//long long tiling(int n) {
//	// 1. �ʱ� �� ��ȯ
//	if (n == 1) return 1;
//
//	// 2. �ذ� ����Ǿ� ������ ������� �ʰ� ��ȯ
//	if (d[n] > 2) return d[n];
//
//	// ������ �ظ� ���ϰ� �����ؾ� ��
//
//	// 3. �ظ� ���ϰ� �����Ѵ�.
//	d[n] = (tiling(n - 1) + tiling(n - 2)) % 10007;
//
//	// 4. �����ϰ� ����, �ظ� ��ȯ �Ѵ�.
//	return d[n];
//}
//
//int main(void) {
//	int n;
//	std::cin >> n;
//	d[0] = 1;
//	d[1] = 1;
//	std::cout << tiling(n);
//	return 0;
//}

// bottom-up

long long d[1001];

int main(void) {
	int n;
	std::cin >> n;
	// 1. �ʱⰪ ���� �� ��ȯ
	d[0] = 1;
	d[1] = 1;
	if (n < 2) std::cout << d[n];

	// 2. n���� iteration
	for (int i = 2; i <= n; i++) {

		// 3. �����ظ� ���ϰ� ����
		d[i] = (d[i - 1] + d[i - 2]) % 10007;
	}

	std::cout << d[n];
	return 0;
}