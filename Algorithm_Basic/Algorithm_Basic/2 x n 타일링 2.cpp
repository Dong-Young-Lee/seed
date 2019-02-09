#include <iostream>
// top-down
//int d[1001] = { 0 };
//
//int tiling2(int n) {
//	// 1. 초기값 반환
//	if (n < 2) return 1;
//
//	// 2. 해가 저장되어 있으면 반환
//	if (d[n] > 1) return d[n];
//
//	// 해가 저장되어 있지 않고, 구해야 함
//
//	// 3. 해를 구하고 저장한다.
//	d[n] = (tiling2(n - 1) + 2 * tiling2(n - 2)) % 10007;
//	
//	// 4. 해를 반환한다.
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