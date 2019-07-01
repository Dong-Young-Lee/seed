#include <iostream>
#include <string.h>
using namespace std;

const int MAX = 20;

int tc, n, t;
int map[MAX][MAX];
int check[101];

int d_r[4] = { 1, 1, -1, -1 };
int d_c[4] = { 1, -1, -1, 1 };

int ans;

void dfs(int sr, int sc, int row, int col, int dir, int length) {
	if (dir == 3 && row == sr && col == sc) {
		if (ans < length) {
			ans = length;
		}
		return;
	}

	int straight_row = row + d_r[dir];
	int straight_col = col + d_c[dir];
	if (straight_row >= 0 && straight_row < n && straight_col >= 0 && straight_col < n) {
		if (check[map[straight_row][straight_col]] != t) {
			check[map[straight_row][straight_col]] = t;
			dfs(sr, sc, straight_row, straight_col, dir, length + 1);
			check[map[straight_row][straight_col]] = 0;
		}
	}

	if (dir != 3) {
		int turn_row = row + d_r[dir + 1];
		int turn_col = col + d_c[dir + 1];
		if (turn_row >= 0 && turn_row < n && turn_col >= 0 && turn_col < n) {
			if (check[map[turn_row][turn_col]] != t) {
				check[map[turn_row][turn_col]] = t;
				dfs(sr, sc, turn_row, turn_col, dir + 1, length + 1);
				check[map[turn_row][turn_col]] = 0;
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(false);

	cin >> tc;
	for (t = 1; t <= tc; t++) {
		ans = -1;

		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				memset(check, 0, sizeof(check));
				dfs(i, j, i, j, 0, 0);
			}
		}

		cout << '#' << t << ' ' << ans << '\n';
	}
	return 0;
}