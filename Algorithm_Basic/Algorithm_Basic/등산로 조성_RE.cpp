#include <iostream>
using namespace std;

typedef struct {
	int row;
	int col;
}info;

const int MAX = 8;

int test_case, T;
int n, k;

int map[MAX][MAX];
int visited[MAX][MAX];

info peak[5];
int peak_num;
int max_height;

int d_r[4] = { -1, 0, 1, 0 };
int d_c[4] = { 0, 1, 0, -1 };

int ans;

void dfs(int row, int col, int len, int cst) {
	if (ans < len) {
		ans = len;
	}

	visited[row][col] = 1;
	int cur_height = map[row][col];

	for (int i = 0; i < 4; i++) {
		info next = { row + d_r[i] , col + d_c[i] };
		if (next.row >= 0 && next.row < n && next.col >= 0 && next.col < n) {
			if (map[next.row][next.col] < cur_height) {
				if (visited[next.row][next.col] == 0) {
					dfs(next.row, next.col, len + 1, cst);
					visited[next.row][next.col] = 0;
				}
			}
			else {
				if (cst == 1) {
					if (visited[next.row][next.col] == 0) {
						if (map[next.row][next.col] - k <= cur_height - 1) {
							int temp = map[next.row][next.col];
							map[next.row][next.col] = cur_height - 1;
							dfs(next.row, next.col, len + 1, 0);
							visited[next.row][next.col] = 0;
							map[next.row][next.col] = temp;
						}
					}
				}
			}
		}
	}
}

void solve() {
	for (int i = 0; i < peak_num; i++) {
		dfs(peak[i].row, peak[i].col, 1, 1);
		visited[peak[i].row][peak[i].col] = 0;
	}
}

void find_peak() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == max_height) {
				peak[peak_num] = { i, j };
				peak_num++;
			}
		}
	}
}

int main(void) {
	cin >> T;
	for (test_case = 1; test_case <= T; test_case++) {
		max_height = 0;
		peak_num = 0;
		ans = 0;

		cin >> n >> k;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				if (map[i][j] > max_height) {
					max_height = map[i][j];
				}
			}
		}

		find_peak();

		solve();

		cout << "#" << test_case << " " << ans << "\n";

	}
	return 0;
}