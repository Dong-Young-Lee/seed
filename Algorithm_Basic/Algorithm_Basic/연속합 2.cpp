#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ld(100001);
vector<int> rd(100001);

vector<int> seq(100001);

int main(void) {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> seq[i];
	}

	ld[1] = seq[1];
	for (int i = 2; i <= n; i++) {
		ld[i] = seq[i];
		if (ld[i - 1] + seq[i] > ld[i]) {
			ld[i] = ld[i - 1] + seq[i];
		}
	}

	rd[n] = seq[n];
	for (int i = n - 1; i >= 1; i--) {
		rd[i] = seq[i];
		if (rd[i + 1] + seq[i] > rd[i]) {
			rd[i] = rd[i + 1] + seq[i];
		}
	}
	
	int ans = ld[1];
	for (int i = 2; i <= n; i++) {
		if (ans < ld[i]) {
			ans = ld[i];
		}
	}

	for (int i = 2; i <= n - 1; i++) {
		if (ans < ld[i - 1] + rd[i + 1]) {
			ans = ld[i - 1] + rd[i + 1];
		}
	}

	cout << ans;

	return 0;
}