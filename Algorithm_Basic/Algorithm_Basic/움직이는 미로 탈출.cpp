#include <iostream>
using namespace std;

typedef struct {
	int row;
	int col;
}info;

const int MAX = 8;
char map[MAX][MAX];
int d_r[9] = { -1, -1, 0, 1, 1, 1, 0, -1, 0 };
int d_c[9] = { 0, 1, 1, 1, 0, -1, -1, -1, 0 };

int ans_flag;

info blocks[MAX * MAX];
int block_cnt;

void dfs(int row, int col) {
	if (ans_flag) return;

	for (int i = 0; i < block_cnt; i++) {
		if (row == blocks[i].row && col == blocks[i].col) {
			return;
		}
	}

	if (row == 0 && col == MAX - 1) {
		ans_flag = 1;
		return;
	}

	for (int i = 0; i < 9; i++) {
		int next_row = row + d_r[i];
		int next_col = col + d_c[i];
		if (next_row >= 0 && next_row < MAX && next_col >= 0 && next_col < MAX) {
			if (map[next_row][next_col] == '.') {

				for (int i = 0; i < block_cnt; i++) {
					if (blocks[i].row < MAX) {
						map[blocks[i].row][blocks[i].col] = '.';
					}
					blocks[i].row++;
				}

				for (int i = 0; i < block_cnt; i++) {
					if (blocks[i].row < MAX) {
						map[blocks[i].row][blocks[i].col] = '#';
					}
				}

				dfs(next_row, next_col);

				for (int i = 0; i < block_cnt; i++) {
					if (blocks[i].row < MAX) {
						map[blocks[i].row][blocks[i].col] = '.';
					}
					blocks[i].row--;
				}

				for (int i = 0; i < block_cnt; i++) {
					if (blocks[i].row < MAX) {
						map[blocks[i].row][blocks[i].col] = '#';
					}
				}
			}
		}
	}
}

int main(void) {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cin >> map[i][j];
			if (map[i][j] == '#') {
				blocks[block_cnt] = { i, j };
				block_cnt++;
			}
		}
	}

	dfs(7, 0);
	if (ans_flag) cout << 1;
	else cout << 0;

	return 0;
}