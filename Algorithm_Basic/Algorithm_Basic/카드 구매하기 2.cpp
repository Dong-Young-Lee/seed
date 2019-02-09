#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// top-down

//vector<int> d(1001, -1);
//vector<int> p(1001, 0);
//
//int min_payment(int n) {
//	if (n == 1) return d[1];
//
//	if (d[n] != -1) {
//		return d[n];
//	}
//
//	for (int i = 1; i <= n; i++) {
//		if (d[n] == -1) {
//			d[n] = p[i] + min_payment(n - i);
//		}
//		else {
//			d[n] = min(d[n], p[i] + min_payment(n - i));
//		}
//	}
//
//	return d[n];
//}
//
//int main(void) {
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		cin >> p[i];
//	}
//	d[0] = 0;
//	d[1] = p[1];
//
//	cout << min_payment(n);
//
//	return 0;
//
//}

// bottom-up

vector<int> d(1001, -1);
vector<int> p(1001, 0);

int main(void) {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	d[0] = 0;
	d[1] = p[1];

	if (n == 1) cout << d[1];

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (d[i] == -1) {
				d[i] = p[j] + d[i - j];
			}
			else {
				d[i] = min(d[i], p[j] + d[i - j]);
			}
		}
	}

	cout << d[n];
	
	return 0;
}