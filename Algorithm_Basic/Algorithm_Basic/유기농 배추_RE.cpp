#include <iostream>
using namespace std;

const int MAX = 50;

int map[MAX][MAX];
int visited[MAX][MAX];
int tc;
int m, n, k;
int ans;

int d_r[4] = { -1, 0, 1, 0 };
int d_c[4] = { 0, 1, 0, -1 };

void dfs(int row, int col) {
	visited[row][col] = 1;
	
	for (int i = 0; i < 4; i++) {
		int next_row = row + d_r[i];
		int next_col = col + d_c[i];
		if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < m) {
			if (!visited[next_row][next_col] && map[next_row][next_col]) {
				dfs(next_row, next_col);
			}
		}
	}
}

int main(void) {
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> m >> n >> k;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				map[i][j] = 0;
				visited[i][j] = 0;
			}
		}
		int r, c;
		for (int i = 0; i < k; i++) {
			cin >> c >> r;
			map[r][c] = 1;
		}

		ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!visited[i][j] && map[i][j]) {
					dfs(i, j);
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}