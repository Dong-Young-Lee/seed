#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

typedef struct {
	int row;
	int col;
}location;

const int MAX = 16;

int t;
int map[MAX][MAX];
int visited[MAX][MAX];

location start;
location end;

int d_r[4] = { -1, 0, 1, 0 };
int d_c[4] = { 0, 1, 0, -1 };

int ans_flag;

void dfs(int row, int col) {
	visited[row][col] = t;
	if (ans_flag) return;
	if (row == end.row && col == end.col) {
		ans_flag = 1;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int next_row = row + d_r[i];
		int next_col = col + d_c[i];

		if (next_row >= 0 && next_row < MAX && next_col >= 0 && next_col < MAX) {
			if (visited[next_row][next_col] != t && map[next_row][next_col] != 1) {
				dfs(next_row, next_col);
			}
		}
	}
}

int main(void) {
	while (t != 10) {
		ans_flag = 0;

		scanf("%d\n", &t);
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				scanf("%1d", &map[i][j]);
				if (map[i][j] == 2) {
					start.row = i;
					start.col = j;
				}
				else if (map[i][j] == 3) {
					end.row = i;
					end.col = j;
				}
			}
			scanf("\n");
		}

		dfs(start.row, start.col);

		if (ans_flag) {
			printf("#%d 1\n", t);
		}
		else {
			printf("#%d 0\n", t);
		}
	}
	return 0;
}