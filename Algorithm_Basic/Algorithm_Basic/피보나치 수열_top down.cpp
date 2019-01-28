#include <iostream>

int d[100] = { 0 };

int fibonacci(int n) {
	if (n <= 1) {
		return 1;
	}
	else {
		if (d[n] > 0) {
			return d[n];
		}
		d[n] = fibonacci(n - 1) + fibonacci(n - 2);
		return d[n];
	}
}

int main(void) {
	d[0] = 0;
	d[1] = 1;

	int n;
	std::cin >> n;
	std::cout << fibonacci(n);

	return 0;

}