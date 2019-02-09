#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// top-down

//vector<int> d(1001, 0);
//vector<int> p(1001, 0);
//
//int payment(int n) {
//	
//	if (n == 1) return d[n];
//
//	if (d[n] > 0) {
//		return d[n];
//	}
//
//	for (int i = 1; i <= n; i++) {
//		d[n] = max(d[n], p[i] + payment(n - i));
//	}
//
//	return d[n];
//	
//}
//
//int main(void) {
//	int n;
//	cin >> n;
//	
//	for (int i = 1; i <= n; i++) {
//		cin >> p[i];
//	}
//	d[1] = p[1];
//
//
//	cout << payment(n);
//
//	return 0;
//
//}

// bottom-up

vector<int> d(1001, 0);
vector<int> p(1001, 0);

int main(void) {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}

	if (n == 1) cout << p[1];
	
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			d[i] = max(d[i], p[j] + d[i - j]);
		}
	}

	cout << d[n];

	return 0;

}