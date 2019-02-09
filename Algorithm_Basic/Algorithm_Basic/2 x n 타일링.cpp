#include <iostream>

// top-down
//
//long long d[1001] = { 0 };
//
//long long tiling(int n) {
//	// 1. 초기 값 반환
//	if (n == 1) return 1;
//
//	// 2. 해가 저장되어 있으면 계산하지 않고 반환
//	if (d[n] > 2) return d[n];
//
//	// 다음은 해를 구하고 저장해야 함
//
//	// 3. 해를 구하고 저장한다.
//	d[n] = (tiling(n - 1) + tiling(n - 2)) % 10007;
//
//	// 4. 저장하고 나서, 해를 반환 한다.
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
	// 1. 초기값 설정 및 반환
	d[0] = 1;
	d[1] = 1;
	if (n < 2) std::cout << d[n];

	// 2. n까지 iteration
	for (int i = 2; i <= n; i++) {

		// 3. 최적해를 구하고 저장
		d[i] = (d[i - 1] + d[i - 2]) % 10007;
	}

	std::cout << d[n];
	return 0;
}