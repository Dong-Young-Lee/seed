#include <iostream>
#include <queue>
using namespace std;

typedef struct {
	int hei;
	int row;
	int col;
}pos;

const int MAX = 100;
int map[MAX][MAX][MAX];

int m, n, h;

queue<pos> q;

int d_h[6] = { 0,0,0,0,-1,1 };
int d_r[6] = { -1,0,1,0,0,0 };
int d_c[6] = { 0,1,0,-1,0,0 };

void bfs() {
	int day = -1;
	while (!q.empty()) {
		int q_size = q.size();
		for (int i = 0; i < q_size; i++) {
			int cur_hei = q.front().hei;
			int cur_row = q.front().row;
			int cur_col = q.front().col;
			q.pop();
			for (int j = 0; j < 6; j++) {
				int next_hei = cur_hei + d_h[j];
				int next_row = cur_row + d_r[j];
				int next_col = cur_col + d_c[j];

				if (next_hei >= 0 && next_hei < h &&
					next_row >= 0 && next_row < n &&
					next_col >= 0 && next_col < m) {
					if (map[next_hei][next_row][next_col] == 0) {
						map[next_hei][next_row][next_col] = 1;
						q.push({ next_hei, next_row, next_col });
					}
				}
			}
		}
		day++;
	}

	int all_flag = 1;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (map[i][j][k] == 0) {
					all_flag = 0;
					break;
				}
			}
			if (!all_flag) break;
		}
		if (!all_flag) break;
	}


	if (!all_flag) cout << -1;
	else {
		cout << day;
	}
}

int main(void) {
	cin >> m >> n >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				int input;
				cin >> input;
				map[i][j][k] = input;
				if (input == 1) {
					q.push({ i, j, k });
				}
			}
		}
	}
	
	bfs();

	return 0;
}