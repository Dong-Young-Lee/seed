// top-down
/*
#include <iostream>
using namespace std;

int d[1000001] = { 0 };

int make_one(int n) {
	if (n == 1) return 0;
	if (d[n] > 0) return d[n];
	
	d[n] = make_one(n - 1) + 1;

	if (n % 3 == 0) {
		int temp = make_one(n / 3) + 1;
		if (d[n] > temp) {
			d[n] = temp;
		}
	}

	if (n % 2 == 0) {
		int temp = make_one(n / 2) + 1;
		if (d[n] > temp) {
			d[n] = temp;
		}
	}

	return d[n];
}

int main(void) {
	int n;
	cin >> n;
	cout << make_one(n);
	return 0;
}
*/

// bottom-up
#include <iostream>
using namespace std;

int d[1000001] = { 0 };

int main(void) {
	int n;
	cin >> n;
	if (n == 1) cout << 0;
	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 1] + 1;
		if (i % 2 == 0) {
			if (d[i] > d[i / 2] + 1) {
				d[i] = d[i / 2] + 1;
			}
		}
		if (i % 3 == 0) {
			if (d[i] > d[i / 3] + 1) {
				d[i] = d[i / 3] + 1;
			}
		}
	}
	cout << d[n];
	return 0;
}