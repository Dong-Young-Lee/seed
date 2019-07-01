#include <iostream>
#include <queue>
using namespace std;

typedef struct {
	int row;
	int col;
	int dir;
}pipe;

const int MAX = 16;

int n;
int map[MAX][MAX];

// 0 : down
// 1 : right
// 2 : right down
int d_r[3] = { 1, 0, 1 };
int d_c[3] = { 0, 1, 1 };

int ans;

void bfs() {
	queue<pipe> q;
	q.push({ 0, 1, 1 });

	while (!q.empty()) {
		int cur_row = q.front().row;
		int cur_col = q.front().col;
		int cur_dir = q.front().dir;
		q.pop();

		if (cur_row == n - 1 && cur_col == n - 1) {
			ans++;
			continue;
		}

		int next_down_row = cur_row + d_r[0];
		int next_down_col = cur_col + d_c[0];

		int next_right_row = cur_row + d_r[1];
		int next_right_col = cur_col + d_c[1];

		int next_dr_row = cur_row + d_r[2];
		int next_dr_col = cur_col + d_c[2];

		if (cur_dir == 0) { // down > down, right down
			if (next_down_row < n) {
				if (map[next_down_row][next_down_col] != 1) {
					q.push({ next_down_row, next_down_col, 0 });
				}
			}
			if (next_dr_row < n && next_dr_col < n) {
				int dr_flag = 1;
				for (int i = 0; i < 3; i++) {
					if (map[cur_row + d_r[i]][cur_col + d_c[i]] == 1) {
						dr_flag = 0;
						break;
					}
				}
				if (dr_flag) {
					q.push({ next_dr_row, next_dr_col, 2 });
				}
			}
		}
		if (cur_dir == 1) { // right > right, right down
			if (next_right_col < n) {
				if (map[next_right_row][next_right_col] != 1) {
					q.push({ next_right_row, next_right_col, 1 });
				}
			}
			if (next_dr_row < n && next_dr_col < n) {
				int dr_flag = 1;
				for (int i = 0; i < 3; i++) {
					if (map[cur_row + d_r[i]][cur_col + d_c[i]] == 1) {
						dr_flag = 0;
						break;
					}
				}
				if (dr_flag) {
					q.push({ next_dr_row, next_dr_col, 2 });
				}
			}
		}
		if (cur_dir == 2) { // right down > down, right, right down
			if (next_down_row < n) {
				if (map[next_down_row][next_down_col] != 1) {
					q.push({ next_down_row, next_down_col, 0 });
				}
			}
			if (next_right_col < n) {
				if (map[next_right_row][next_right_col] != 1) {
					q.push({ next_right_row, next_right_col, 1 });
				}
			}
			if (next_dr_row < n && next_dr_col < n) {
				int dr_flag = 1;
				for (int i = 0; i < 3; i++) {
					if (map[cur_row + d_r[i]][cur_col + d_c[i]] == 1) {
						dr_flag = 0;
						break;
					}
				}
				if (dr_flag) {
					q.push({ next_dr_row, next_dr_col, 2 });
				}
			}
		}
	}
}

void get_input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
}

int main(void) {
	get_input();
	bfs();
	cout << ans;
	return 0;
}