#include <iostream>
using namespace std;
int n;
int digits;
int ans = 0;

void find_digits() {
	int divisor = 1;
	int quotient = n;
	digits = 0;
	while (quotient != 0) {
		digits++;
		quotient = n / divisor;
		divisor *= 10;
	}
	digits--;
}

int main(void) {
	cin >> n;
	find_digits();

	int dividend = n;
	int divisor = 1;

	for (int i = digits; i >= 1; i--) {
		if (i == digits) {
			divisor = 1;
			for (int j = 1; j < i; j++) {
				divisor *= 10;
			}
			ans += ((dividend - divisor + 1) * i);
		}
		else if (i == 1) {
			if (digits == 1) {
				ans = n;
			}
			else {
				ans += 9;
			}
		}
		else {
			int temp = 1;
			for (int j = 0; j < i; j++) {
				temp *= 10;
			}
			ans += (i*(temp-(temp/10)));
		}
	}

	cout << ans;

	return 0;
}