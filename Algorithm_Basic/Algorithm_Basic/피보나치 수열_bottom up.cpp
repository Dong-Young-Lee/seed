#include <iostream>

int d[100];

int fibonacci(int n) {
	d[0] = 0;
	d[1] = 1;
	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 1] + d[i - 2];
	}
	return d[n];
}

int main(void) {
	int n;
	std::cin >> n;

	std::cout << fibonacci(n);
	return 0;
}