#include <iostream>

// top-down
//int d[11] = { 0 };
//
//int plus(int n) {
//	// 1. �ʱⰪ ��ȯ
//	if (n < 3) return d[n];
//
//	// 2. �ذ� ����Ǿ� ������ ��ȯ
//	if (d[n] > 2) return d[n];
//	
//	// 3. �ظ� ���ϰ� ����
//	d[n] = plus(n - 1) + plus(n - 2) + plus(n - 3);
//	
//	// 4. �ظ� ��ȯ
//	return d[n];
//}
//
//int main(void) {
//	int t, n;
//	std::cin >> t;
//	d[0] = 1;
//	d[1] = 1;
//	d[2] = 2;
//	while (t--) {
//		std::cin >> n;
//		std::cout << plus(n) << '\n';
//	}
//	return 0;
//}

// bottom-up
int d[11];

int main(void) {
	int t;
	std::cin >> t;

	d[0] = 1;
	d[1] = 1;
	d[2] = 2;

	while (t--) {
		int n;
		std::cin >> n;
		
		if (n < 3) {
			std::cout << d[n] << '\n';
			continue;
		}
		
		for (int i = 3; i <= n; i++) {
			d[i] = d[i - 1] + d[i - 2] + d[i - 3];
		}
		
		std::cout << d[n] << '\n';
	}

	return 0;
}