#include <iostream>
using namespace std;

const int MAX = 16;

int n;
int map[MAX][MAX];

int ans;

int d_r[3] = { 0, 1, 1 };
int d_c[3] = { 1, 1, 0 };

void dfs(int row, int col, int dir) {
	if (row == n - 1 && col == n - 1) {
		ans++;
		return;
	}

	if (dir == 0) {
		for (int i = 0; i < 2; i++) {
			int next_row = row + d_r[i];
			int next_col = col + d_c[i];
			if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < n) {
				if (i == 0) {
					if (map[next_row][next_col] == 0) {
						dfs(next_row, next_col, i);
					}
				}
				else if (i == 1) {
					int can_go = 1;
					for (int j = 0; j < 3; j++) {
						if (map[row + d_r[j]][col + d_c[j]] != 0) {
							can_go = 0;
							break;
						}
					}
					if (can_go) {
						dfs(next_row, next_col, i);
					}
				}
			}
		}
	}
	else if (dir == 1) {
		for (int i = 0; i < 3; i++) {
			int next_row = row + d_r[i];
			int next_col = col + d_c[i];
			if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < n) {
				if (i == 0 || i == 2) {
					if (map[next_row][next_col] == 0) {
						dfs(next_row, next_col, i);
					}
				}
				else if (i == 1) {
					int can_go = 1;
					for (int j = 0; j < 3; j++) {
						if (map[row + d_r[j]][col + d_c[j]] != 0) {
							can_go = 0;
							break;
						}
					}
					if (can_go) {
						dfs(next_row, next_col, i);
					}
				}
			}
		}
	}
	else {
		for (int i = 1; i < 3; i++) {
			int next_row = row + d_r[i];
			int next_col = col + d_c[i];
			if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < n) {
				if (i == 2) {
					if (map[next_row][next_col] == 0) {
						dfs(next_row, next_col, i);
					}
				}
				else if (i == 1) {
					int can_go = 1;
					for (int j = 0; j < 3; j++) {
						if (map[row + d_r[j]][col + d_c[j]] != 0) {
							can_go = 0;
							break;
						}
					}
					if (can_go) {
						dfs(next_row, next_col, i);
					}
				}
			}
		}
	}
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	dfs(0, 1, 0);

	cout << ans;

	return 0;
}