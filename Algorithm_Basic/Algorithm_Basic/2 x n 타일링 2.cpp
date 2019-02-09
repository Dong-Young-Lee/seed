#include <iostream>
// top-down
//int d[1001] = { 0 };
//
//int tiling2(int n) {
//	// 1. �ʱⰪ ��ȯ
//	if (n < 2) return 1;
//
//	// 2. �ذ� ����Ǿ� ������ ��ȯ
//	if (d[n] > 1) return d[n];
//
//	// �ذ� ����Ǿ� ���� �ʰ�, ���ؾ� ��
//
//	// 3. �ظ� ���ϰ� �����Ѵ�.
//	d[n] = (tiling2(n - 1) + 2 * tiling2(n - 2)) % 10007;
//	
//	// 4. �ظ� ��ȯ�Ѵ�.
//	return d[n];
//}
//
//int main(void) {
//	int n;
//	std::cin >> n;
//	d[0] = 1;
//	d[1] = 1;
//	std::cout << tiling2(n);
//	return 0;
//}

// bottom-up
int d[1001];

int main(void) {
	int n;
	std::cin >> n;
	d[0] = 1;
	d[1] = 1;
	
	if (n < 2) std::cout << d[n];

	for (int i = 2; i <= n; i++) {
		d[i] = (d[i - 1] + 2 * d[i - 2]) % 10007;
	}

	std::cout << d[n];
	return 0;
}