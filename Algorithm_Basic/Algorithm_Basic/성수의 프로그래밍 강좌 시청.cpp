#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 200;

int T, t;
int n, k;
double input[MAX];
double ans;

void solve() {
	for (int i = n-k; i < n; i++) {
		ans = (ans + input[i]) / 2;
	}
}

int main(void) {
	cin >> T;
	for (t = 1; t <= T; t++) {
		ans = 0;

		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> input[i];
		}
		sort(input, input + n);

		solve();

		cout << "#" << t << " " << ans << '\n';
	}
	return 0;
}