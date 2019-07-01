#include <iostream>
#include <queue>
using namespace std;
typedef struct {
	int row;
	int col;
	int dir;
	int inst;
}info;

const int MAX = 100;

int n, m;
int map[MAX][MAX];
int visited[MAX][MAX][4];
info arrival;
queue<info> q;

int d_r[4] = { -1, 0, 1, 0 };
int d_c[4] = { 0, 1, 0, -1 };

void bfs() {
	visited[q.front().row][q.front().col][q.front().dir] = 1;
	while (!q.empty()) {
		info cur = q.front();
		q.pop();

		if (cur.row == arrival.row && cur.col == arrival.col && cur.dir == arrival.dir) {
			cout << cur.inst;
			return;
		}

		int next_row = cur.row;
		int next_col = cur.col;
		for (int i = 0; i < 3; i++) {
			next_row += d_r[cur.dir];
			next_col += d_c[cur.dir];
			if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < m) {
				if (map[next_row][next_col] == 0) {
					if (visited[next_row][next_col][cur.dir] == 0) {
						visited[next_row][next_col][cur.dir] = 1;
						q.push({ next_row, next_col, cur.dir, cur.inst + 1 });
					}
				}
				else {
					break;
				}
			}
			else {
				break;
			}
		}

		int left_dir = (cur.dir + 3) % 4;
		if (visited[cur.row][cur.col][left_dir] == 0) {
			visited[cur.row][cur.col][left_dir] = 1;
			q.push({ cur.row, cur.col, left_dir, cur.inst + 1 });
		}

		int right_dir = (cur.dir + 1) % 4;
		if (visited[cur.row][cur.col][right_dir] == 0) {
			visited[cur.row][cur.col][right_dir] = 1;
			q.push({ cur.row, cur.col, right_dir, cur.inst + 1 });
		}
	}


}

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	cin >> arrival.row >> arrival.col >> arrival.dir;
	arrival.row--;
	arrival.col--;
	if (arrival.dir == 2) {
		arrival.dir = 3;
	}
	else if (arrival.dir == 3) {
		arrival.dir = 2;
	}
	else if (arrival.dir == 4) {
		arrival.dir = 0;
	}
	arrival.inst = 0;
	q.push(arrival);

	cin >> arrival.row >> arrival.col >> arrival.dir;

	arrival.row--;
	arrival.col--;
	if (arrival.dir == 2) {
		arrival.dir = 3;
	}
	else if (arrival.dir == 3) {
		arrival.dir = 2;
	}
	else if (arrival.dir == 4) {
		arrival.dir = 0;
	}

	bfs();

	return 0;
}