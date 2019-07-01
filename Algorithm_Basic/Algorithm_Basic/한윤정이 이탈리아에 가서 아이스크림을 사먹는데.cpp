#include <iostream>
using namespace std;

int cunnected[200][200];
int n, m;
int ans;

void solve() {
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			if (cunnected[i][j]) continue;
			for (int k = j + 1; k < n; k++) {
				if (cunnected[j][k] || cunnected[k][i]) continue;
				ans++;
			}
		}
	}
}

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		cunnected[u - 1][v - 1] = 1;
		cunnected[v - 1][u - 1] = 1;
	}

	solve();
	cout << ans;
	return 0;
}