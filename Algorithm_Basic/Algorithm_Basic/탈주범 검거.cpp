#include <iostream>
#include <queue>
using namespace std;

const int MAX = 50;
int test_case, T;
int n, m, r, c, l;

int map[MAX][MAX];
int visited[MAX][MAX];
queue < pair<int, int> > q;

int d_r[4] = { -1, 0, 1, 0 };
int d_c[4] = { 0, 1, 0, -1 };

int ans;

int is_valid(int row, int col, int dir, int cur_next) {
	int open[4] = { 0, };
	int num = map[row][col];

	int index = 3;
	int divisor = 8;
	while (divisor != 0) {
		if (num / divisor > 0) {
			open[index] = 1;
		}
		num %= divisor;
		divisor >>= 1;
		index--;
	}

	if (cur_next) {
		if (open[(dir + 2) % 4]) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		if (open[dir]) {
			return 1;
		}
		else {
			return 0;
		}
	}
}

void bfs() {
	ans = 1;
	q.push({ r, c });
	visited[r][c] = test_case;

	l--;
	while (l--) {
		int q_size = q.size();
		for (int j = 0; j < q_size; j++) {
			int cur_row = q.front().first;
			int cur_col = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				if (is_valid(cur_row, cur_col, i, 0)) {
					int next_row = cur_row + d_r[i];
					int next_col = cur_col + d_c[i];

					if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < m) {
						if (visited[next_row][next_col] != test_case && map[next_row][next_col] != 0) {
							if (is_valid(next_row, next_col, i, 1)) {
								ans++;
								visited[next_row][next_col] = test_case;
								q.push({ next_row, next_col });
							}
						}
					}
				}
			}
		}
	}

	while (!q.empty()) {
		q.pop();
	}

}

int main(int argc, char** argv) {
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case) {
		cin >> n >> m >> r >> c >> l;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int input;
				cin >> input;
				if (input == 1) {
					map[i][j] = 15;
				}
				else if (input == 2) {
					map[i][j] = 5;
				}
				else if (input == 3) {
					map[i][j] = 10;
				}
				else if (input == 4) {
					map[i][j] = 3;
				}
				else if (input == 5) {
					map[i][j] = 6;
				}
				else if (input == 6) {
					map[i][j] = 12;
				}
				else if (input == 7) {
					map[i][j] = 9;
				}
				else {
					map[i][j] = 0;
				}
			}
		}

		bfs();

		cout << "#" << test_case << " " << ans << "\n";

	}
	return 0;
}