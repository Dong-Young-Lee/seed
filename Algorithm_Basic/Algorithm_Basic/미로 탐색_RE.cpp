#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
using namespace std;

const int MAX = 100;

int n, m;
int map[MAX][MAX];
int visited[MAX][MAX];

int d_r[4] = { -1, 0, 1, 0 };
int d_c[4] = { 0, 1, 0, -1 };

void bfs() {
	int cnt = 1;
	queue< pair<int, int> > q;
	q.push(make_pair(0, 0));
	visited[0][0] = cnt;

	while (!q.empty()) {
		int q_size = q.size();
		for (int i = 0; i < q_size; i++) {
			int cur_row = q.front().first;
			int cur_col = q.front().second;
			q.pop();

			if (cur_row == n - 1 && cur_col == m - 1) {
				printf("%d", visited[n-1][m-1]);
				return;
			}

			for (int j = 0; j < 4; j++) {
				int next_row = cur_row + d_r[j];
				int next_col = cur_col + d_c[j];
				if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < m) {
					if (!visited[next_row][next_col] && map[next_row][next_col]) {
						visited[next_row][next_col] = visited[cur_row][cur_col] + 1;
						q.push(make_pair(next_row, next_col));
					}
				}
			}

		}
	}
}

int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	
	bfs();

	return 0;
}
