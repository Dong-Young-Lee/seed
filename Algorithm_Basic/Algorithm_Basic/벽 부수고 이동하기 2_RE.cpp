#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
using namespace std;

typedef struct {
	int row;
	int col;
	int crash;
}info;

const int MAX = 1000;
int n, m, k;
int map[MAX][MAX];
int visited[MAX][MAX][11];
queue<info> q;

int d_r[4] = { -1, 0, 1, 0 };
int d_c[4] = { 0, 1, 0, -1 };

int ans = -1;

void bfs() {
	visited[0][0][0] = 1;
	q.push({ 0, 0, 0 });
	int dist = 1;

	while (!q.empty()) {
		int q_size = q.size();
		for (int i = 0; i < q_size; i++) {
			info cur = q.front();
			q.pop();

			if (cur.row == n - 1 && cur.col == m - 1) {
				ans = dist;
				return;
			}

			for (int j = 0; j < 4; j++) {
				int next_row = cur.row + d_r[j];
				int next_col = cur.col + d_c[j];
				if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < m) {
					if (map[next_row][next_col] == 1) {
						if (cur.crash < k) {
							if (visited[next_row][next_col][cur.crash + 1] == 0) {
								visited[next_row][next_col][cur.crash + 1] = 1;
								q.push({ next_row, next_col, cur.crash + 1 });
							}
						}
					}
					else {
						if (visited[next_row][next_col][cur.crash] == 0) {
							visited[next_row][next_col][cur.crash] = 1;
							q.push({ next_row, next_col, cur.crash });
						}
					}
				}
			}
		}
		dist++;
	}
}
int main(void) {
	scanf("%d %d %d\n", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d\n", &map[i][j]);
		}
	}

	bfs();
	printf("%d", ans);

	return 0;
}