#include <iostream>
#include <queue>
using namespace std;

typedef struct {
	int row;
	int col;
	int num;
}info;

int test_case, T;
int n, w, h;

int map[15][12];
int map_copyed[15][12];

int visited[15][12];
int v;

int numbers[4];
int used_numbers;

queue<info> q;

int d_r[4] = { -1, 0, 1, 0 };
int d_c[4] = { 0, 1, 0, -1 };

int ans;

void copy_map() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			map[i][j] = map_copyed[i][j];
		}
	}
}

void print_map() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void find_ans() {
	int cnt = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (map[i][j] != 0) {
				cnt++;
			}
		}
	}
	if (ans > cnt) {
		ans = cnt;
	}
}

void down_map() {
	for (int c = 0; c < w; c++) {
		for (int r = h - 2; r >= 0; r--) {
			if (map[r][c] != 0) {
				int empty = 0;
				int max_empty = h - r - 1;
				for (int k = 1; k <= max_empty; k++) {
					if (map[r + k][c] != 0) {
						break;
					}
					empty++;
				}
				if (empty > 0) {
					map[r + empty][c] = map[r][c];
					map[r][c] = 0;
				}
			}
		}
	}
}

void bfs(int row, int col) {
	q.push({ row, col, map[row][col] });
	visited[row][col] = v;

	while (!q.empty()) {
		info cur = { q.front().row, q.front().col, q.front().num };
		q.pop();
		map[cur.row][cur.col] = 0;

		for (int i = 0; i < 4; i++) {
			int next_row = cur.row;
			int next_col = cur.col;
			for (int j = 0; j < cur.num - 1; j++) {
				next_row += d_r[i];
				next_col += d_c[i];
				if (next_row >= 0 && next_row < h && next_col >= 0 && next_col < w) {
					if (map[next_row][next_col] != 0) {
						if (visited[next_row][next_col] != v) {
							visited[next_row][next_col] = v;
							q.push({ next_row, next_col, map[next_row][next_col] });
						}
					}
				}
			}
		}
	}
}

int find_row(int col) {
	for (int i = 0; i < h; i++) {
		if (map[i][col] != 0) {
			return i;
		}
	}
	return -1;
}

void simulate() {
	for (int i = 0; i < n; i++) {
		int row = find_row(numbers[i]);
		if (row >= 0) {
			bfs(row, numbers[i]);
			v++;
			down_map();
		}
	}
}

void repet_perm() {
	if (ans == 0) return;

	if (used_numbers == n) {

		simulate();
		find_ans();
		copy_map();

		return;
	}
	for (int i = 0; i < w; i++) {
		int row = find_row(i);
		if (row >= 0) {
			numbers[used_numbers] = i;
			used_numbers++;
			repet_perm();
			used_numbers--;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	for (test_case = 1; test_case <= T; test_case++) {
		v = 1;
		ans = 2147483647;

		cin >> n >> w >> h;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map_copyed[i][j];
			}
		}
		copy_map();
		repet_perm();

		cout << "#" << test_case << " " << ans << "\n";

	}
	return 0;
}