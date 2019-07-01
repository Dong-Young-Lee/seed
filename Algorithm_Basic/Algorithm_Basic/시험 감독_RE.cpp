#include <iostream>
using namespace std;

int n;
int room[1000000];

int a, b;

long long ans;

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> room[i];
	}
	cin >> a >> b;

	for (int i = 0; i < n; i++) {
		room[i] -= a;
		ans++;
		if (room[i] >= 0) {
			int quotient = room[i] / b;
			int remain = room[i] % b;
			if (remain > 0) {
				ans += quotient + 1;
			}
			else {
				ans += quotient;
			}
		}
	}

	cout << ans;

	return 0;
}