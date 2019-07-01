#include <iostream>
using namespace std;

const int MAX = 20;

int test_case, T;
int n;
int map[MAX][MAX];

int d_r[4] = { 1, 1, -1, -1 };
int d_c[4] = { 1, -1, -1, 1 };

int is_used[101];
int s_row, s_col;

int ans;

void dfs(int row, int col, int turn, int len) {
	if (turn == 3) {
		if (row == s_row && col == s_col) {
			if (ans < len - 1) {
				ans = len - 1;
			}
			return;
		}
	}

	is_used[map[row][col]] = 1;

	// straight
	int stra_row = row + d_r[turn];
	int stra_col = col + d_c[turn];
	if (stra_row >= 0 && stra_row < n && stra_col >= 0 && stra_col < n) {
		if (is_used[map[stra_row][stra_col]] == 0 || (stra_row == s_row && stra_col == s_col)) {
			dfs(stra_row, stra_col, turn, len + 1);
			if (stra_row != s_row || stra_col != s_col) {
				is_used[map[stra_row][stra_col]] = 0;
			}
		}
	}

	// turn
	if (turn < 3 && (row != s_row || col != s_col)) {
		int turn_row = row + d_r[turn + 1];
		int turn_col = col + d_c[turn + 1];
		if (turn_row >= 0 && turn_row < n && turn_col >= 0 && turn_col < n) {
			if (is_used[map[turn_row][turn_col]] == 0 || (turn_row == s_row && turn_col == s_col)) {
				dfs(turn_row, turn_col, turn + 1, len + 1);
				if (turn_row != s_row || turn_col != s_col) {
					is_used[map[turn_row][turn_col]] = 0;
				}
			}
		}
	}
}

void solve() {
	for (int r = 0; r < n - 1; r++) {
		for (int c = 1; c < n - 1; c++) {
			s_row = r;
			s_col = c;
			dfs(r, c, 0, 1);
			is_used[map[s_row][s_col]] = 0;
		}
	}
}


int main(void) {
	cin >> T;
	for (test_case = 1; test_case <= T; test_case++) {
		ans = -1;

		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}

		solve();

		cout << "#" << test_case << " " << ans << "\n";
	}

	return 0;
}