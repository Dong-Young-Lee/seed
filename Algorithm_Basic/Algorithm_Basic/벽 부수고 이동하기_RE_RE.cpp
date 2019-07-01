#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
using namespace std;

typedef struct {
	int row;
	int col;
	int stat;
}info;

const int MAX = 1000;
int map[MAX][MAX];
int n, m;

int d_r[4] = { -1, 0, 1, 0 };
int d_c[4] = { 0, 1, 0, -1 };

int visited[MAX][MAX][2];

queue<info> q;

int ans = -1;

void bfs() {
	q.push({ 0, 0, 0 });
	visited[0][0][0] = 1;
	
	while (!q.empty()) {
		int cur_row = q.front().row;
		int cur_col = q.front().col;
		int cur_stat = q.front().stat;
		q.pop();

		if (cur_row == n - 1 && cur_col == m - 1) {
			ans = visited[cur_row][cur_col][cur_stat];
			return;
		}

		for (int i = 0; i < 4; i++) {
			int next_row = cur_row + d_r[i];
			int next_col = cur_col + d_c[i];

			if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < m) {
				if (map[next_row][next_col] == 0) {
					if (visited[next_row][next_col][cur_stat] == 0) {
						visited[next_row][next_col][cur_stat] = visited[cur_row][cur_col][cur_stat] + 1;
						q.push({ next_row, next_col, cur_stat });
					}
				}
				else {
					if (cur_stat == 0) {
						if (visited[next_row][next_col][1] == 0) {
							visited[next_row][next_col][1] = visited[cur_row][cur_col][cur_stat] + 1;
							q.push({ next_row, next_col, 1 });
						}
					}
				}
			}
		}
	}
}

int main(void) {
	scanf("%d %d\n", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d\n", &map[i][j]);
		}
	}

	bfs();
	
	printf("%d", ans);

	return 0;
}