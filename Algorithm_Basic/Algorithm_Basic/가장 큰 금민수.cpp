#include <iostream>
using namespace std;

int n;

int find_km_number(int num) {
	while (num > 0) {
		if (num % 10 != 4 && num % 10 != 7) {
			return 0;
		}
		num /= 10;
	}
	return 1;
}

int main(void) {
	cin >> n;
	for (int i = n; i >= 4; i--) {
		if (find_km_number(i)) {
			cout << i;
			break;
		}
	}
	return 0;
}