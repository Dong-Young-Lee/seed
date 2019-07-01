#include <iostream>
using namespace std;

typedef struct {
	int row;
	int col;
	int dir;
}ball_info;

typedef struct {
	int row;
	int col;
	int num;
}hole_info;

const int MAX = 100;
int test_case, T, n;
int map[MAX][MAX];

ball_info ball;
hole_info hole[10];
int hole_cnt;

int d_r[4] = { -1, 0, 1, 0 };
int d_c[4] = { 0, 1, 0, -1 };

int ans;

void play(int row, int col, int dir) {
	ball = { row, col, dir };

	int score = 0;
	while (true) {
		// cout << "(" << ball.row << ", " << ball.col << ", " << ball.dir << ")\n";

		int next_row = ball.row + d_r[ball.dir];
		int next_col = ball.col + d_c[ball.dir];
		int next_dir = ball.dir;
		int back_dir = (ball.dir + 2) % 4;

		if (next_row == -1 || next_row == n || next_col == -1 || next_col == n) {
			score++;
			ball = { next_row, next_col, back_dir };
		}
		else if (map[next_row][next_col] == 1) {
			score++;
			if (ball.dir == 2) {
				next_dir = 1;
			}
			else if (ball.dir == 3) {
				next_dir = 0;
			}
			else {
				next_dir = back_dir;
			}
			ball = { next_row, next_col, next_dir };
		}
		else if (map[next_row][next_col] == 2) {
			score++;
			if (ball.dir == 0) {
				next_dir = 1;
			}
			else if (ball.dir == 3) {
				next_dir = 2;
			}
			else {
				next_dir = back_dir;
			}
			ball = { next_row, next_col, next_dir };
		}
		else if (map[next_row][next_col] == 3) {
			score++;
			if (ball.dir == 0) {
				next_dir = 3;
			}
			else if (ball.dir == 1) {
				next_dir = 2;
			}
			else {
				next_dir = back_dir;
			}
			ball = { next_row, next_col, next_dir };
		}
		else if (map[next_row][next_col] == 4) {
			score++;
			if (ball.dir == 1) {
				next_dir = 0;
			}
			else if (ball.dir == 2) {
				next_dir = 3;
			}
			else {
				next_dir = back_dir;
			}
			ball = { next_row, next_col, next_dir };
		}
		else if (map[next_row][next_col] == 5) {
			score++;
			ball = { next_row, next_col, back_dir };
		}
		else if (map[next_row][next_col] >= 6 && map[next_row][next_col] <= 10) {
			for (int i = 0; i < hole_cnt; i++) {
				if (map[next_row][next_col] == hole[i].num) {
					if (next_row != hole[i].row || next_col != hole[i].col) {
						next_row = hole[i].row;
						next_col = hole[i].col;
						break;
					}
				}
			}
			ball = { next_row, next_col, next_dir };
		}
		else if (map[next_row][next_col] == -1) {
			if (ans < score) {
				ans = score;
			}
			break;
		}
		else if (next_row == row && next_col == col) {
			if (ans < score) {
				ans = score;
			}
			break;
		}
		else {
			ball = { next_row, next_col, next_dir };
		}
	}
}

void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 4; k++) {
				if (map[i][j] == 0) {
					// cout << "test : (" << i << ", " << j << ", " << k << ")\n";
					play(i, j, k);
				}
			}
		}
	}
}

int main(void) {
	cin >> T;
	for (test_case = 1; test_case <= T; test_case++) {
		ans = 0;
		hole_cnt = 0;

		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				if (map[i][j] >= 6 && map[i][j] <= 10) {
					hole[hole_cnt++] = { i, j, map[i][j] };
				}
			}
		}

		solve();

		cout << "#" << test_case << " " << ans << "\n";

	}

	return 0;
}