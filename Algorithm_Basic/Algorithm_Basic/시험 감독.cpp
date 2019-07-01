#include <iostream>
using namespace std;

int n, b, c;
long long ans;
int input[1000000];

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		input[i] = num;
	}
	cin >> b >> c;

	for (int i = 0; i < n; i++) {
		input[i] -= b;
		ans++;
		if (input[i] > 0) {
			if (input[i] / c > 0) {
				if (input[i] % c > 0) {
					ans += (input[i] / c) + 1;
				}
				else {
					ans += input[i] / c;
				}
			}
			else {
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}