#include <iostream>

// top-down
//int d[11] = { 0 };
//
//int plus(int n) {
//	// 1. 초기값 반환
//	if (n < 3) return d[n];
//
//	// 2. 해가 저장되어 있으면 반환
//	if (d[n] > 2) return d[n];
//	
//	// 3. 해를 구하고 저장
//	d[n] = plus(n - 1) + plus(n - 2) + plus(n - 3);
//	
//	// 4. 해를 반환
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