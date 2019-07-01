#include <iostream>
using namespace std;

const int MAX = 1000000001;

int tc, test;
long long ans;

void dfs(long long s, long long t, long long a, long long b, long long day) {
	if (s > t) return;
	if (s == t) {
		if (ans > day) {
			ans = day;
		}
		return;
	}

	dfs(s + a, t, a, b, day + 1);
	dfs(s * b, t, a, b, day + 1);
}

int main(void) {
	cin >> tc;
	for (test = 1; test <= tc; test++) {
		long long s, t, a, b;
		cin >> s >> t >> a >> b;

		ans = MAX;
		dfs(s, t, a, b, 0);
		if (ans == MAX) {
			cout << '#' << test << ' ' << -1 << '\n';
		}
		else {
			cout << '#' << test << ' ' << ans << '\n';
		}
	}
	return 0;
}