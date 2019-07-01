#include <iostream>
#include <queue>
using namespace std;

typedef struct {
	int row;
	int col;
	int stat;
}info;

const int MAX = 200;
int k, w, h;
int map[MAX][MAX];
int visited[MAX][MAX][31];

int d_r[4] = { -1, 0, 1, 0 };
int d_c[4] = { 0, 1, 0, -1 };

int kd_r[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int kd_c[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

queue<info> q;

int ans = -1;

void bfs() {
	q.push({ 0, 0, k });

	while (!q.empty()) {
		int cur_row = q.front().row;
		int cur_col = q.front().col;
		int cur_stat = q.front().stat;
		q.pop();

		if (cur_row == h - 1 && cur_col == w - 1) {
			ans = visited[cur_row][cur_col][cur_stat];
			return;
		}

		for (int i = 0; i < 4; i++) {
			int next_row = cur_row + d_r[i];
			int next_col = cur_col + d_c[i];
			if (next_row >= 0 && next_row < h && next_col >= 0 && next_col < w) {
				if (map[next_row][next_col] == 0) {
					if (visited[next_row][next_col][cur_stat] == 0) {
						visited[next_row][next_col][cur_stat] = visited[cur_row][cur_col][cur_stat] + 1;
						q.push({ next_row, next_col, cur_stat });
					}
				}
			}
		}

		if (cur_stat > 0) {
			for (int i = 0; i < 8; i++) {
				int next_row = cur_row + kd_r[i];
				int next_col = cur_col + kd_c[i];
				if (next_row >= 0 && next_row < h && next_col >= 0 && next_col < w) {
					if (map[next_row][next_col] == 0) {
						if (visited[next_row][next_col][cur_stat - 1] == 0) {
							visited[next_row][next_col][cur_stat - 1] = visited[cur_row][cur_col][cur_stat] + 1;
							q.push({ next_row, next_col, cur_stat - 1 });
						}

					}
				}
			}
		}

	}
}

int main(void) {
	cin >> k >> w >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> map[i][j];
		}
	}

	bfs();
	
	cout << ans;

	return 0;
}