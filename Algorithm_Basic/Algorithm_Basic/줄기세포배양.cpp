#include <iostream>
#include <queue>
using namespace std;

typedef struct {
	int hp;
	int state; // 0 1 2
	int time;
}map_info;

typedef struct {
	int row;
	int col;
	int hp;
	int state; // 0 1 2
	int time;
}cell_info;

int test_case, T, n, m, k;

map_info map[350][350];
queue<cell_info> cell_q;

int d_r[4] = { -1, 0, 1, 0 };
int d_c[4] = { 0, 1, 0, -1 };

int ans;

void init() {
	for (int i = 0; i < 350; i++) {
		for (int j = 0; j < 350; j++) {
			map[i][j] = { 0, 0, 0 };
		}
	}
	while (!cell_q.empty()) {
		cell_q.pop();
	}
}

void bfs() {
	int time = 0;
	while (time < k) {

		queue<cell_info> cell_cmp;

		int cell_num = cell_q.size();
		for (int i = 0; i < cell_num; i++) {
			cell_info cur = cell_q.front();
			cell_q.pop();

			if (cur.state == 0) {
				cur.time++;
				if (cur.hp == cur.time) {
					cur.state = 1;
					cur.time = 0;
					cell_q.push(cur);
					map[cur.row][cur.col].state = 1;
					map[cur.row][cur.col].time = 0;
				}
				else {
					cell_q.push(cur);
					map[cur.row][cur.col].time++;
				}
			}
			else if (cur.state == 1) {
				cur.time++;
				if (cur.time == 1) {
					for (int i = 0; i < 4; i++) {
						int next_row = cur.row + d_r[i];
						int next_col = cur.col + d_c[i];
						if (map[next_row][next_col].hp == 0) {
							cell_q.push({ next_row, next_col, cur.hp, 0, 0 });
							map[next_row][next_col] = { cur.hp, 0, 0 };
						}
						else {
							if (map[next_row][next_col].hp < cur.hp) {
								if (map[next_row][next_col].state == 0 && map[next_row][next_col].time == 0) {
									cell_cmp.push({ next_row, next_col, cur.hp, 0, 0 });
								}
							}
						}
					}
				}
				if (cur.time < cur.hp) {
					cell_q.push(cur);
					map[cur.row][cur.col].time++;
				}
				else if (cur.time == cur.hp) {
					map[cur.row][cur.col] = { cur.hp, 2, 0 };
				}
			}

		}

		int cmp_num = cell_cmp.size();
		for (int i = 0; i < cmp_num; i++) {
			cell_info cur = cell_cmp.front();
			if (map[cur.row][cur.col].state == 0 && map[cur.row][cur.col].time == 0) {

				int cur_cell_num = cell_q.size();
				for (int j = 0; j < cur_cell_num; j++) {
					if (cell_q.front().row == cur.row && cell_q.front().col == cur.col) {
						cell_q.pop();
					}
					else {
						cell_q.push(cell_q.front());
						cell_q.pop();
					}
				}

				cell_q.push(cur);
				map[cur.row][cur.col] = { cur.hp, 0, 0 };
			}
			cell_cmp.pop();
		}
		time++;
	}

	ans = cell_q.size();
}

int main(void) {
	cin >> T;
	for (test_case = 1; test_case <= T; test_case++) {
		// init
		init();
		cin >> n >> m >> k;
		for (int i = 150; i < n + 150; i++) {
			for (int j = 150; j < m + 150; j++) {
				cin >> map[i][j].hp;
				if (map[i][j].hp > 0) {
					cell_q.push({ i, j, map[i][j].hp, 0, 0 });
				}
			}
		}

		bfs();

		cout << "#" << test_case << " " << ans << "\n";

	}
	return 0;
}