#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <deque>
using namespace std;
int m, n;
int maze[101][101];
int wall[101][101];
int visited[101][101];
deque< pair<int, int> > d;

int d_row[4] = {-1, 0, 1, 0};
int d_col[4] = {0, 1, 0, -1};

void bfs() {
	d.push_back(make_pair(1, 1));
	visited[1][1] = 1;
	wall[1][1] = 0;

	while (!d.empty()) {
		int cur_row = d.front().first;
		int cur_col = d.front().second;
		int cur_wall = wall[cur_row][cur_col];
		d.pop_front();

		for (int i = 0; i < 4; i++) {
			int adj_row = cur_row + d_row[i];
			int adj_col = cur_col + d_col[i];
			if (adj_row >= 1 && adj_row <= n &&
				adj_col >= 1 && adj_col <= m) {
				if (maze[adj_row][adj_col] == 0 && visited[adj_row][adj_col] == 0) {
					d.push_front(make_pair(adj_row, adj_col));
					visited[adj_row][adj_col] = 1;
					wall[adj_row][adj_col] = cur_wall;
				}
				if (maze[adj_row][adj_col] == 1 && visited[adj_row][adj_col] == 0) {
					d.push_back(make_pair(adj_row, adj_col));
					visited[adj_row][adj_col] = 1;
					wall[adj_row][adj_col] = cur_wall + 1;
				}
				if (adj_row == n && adj_col == m) {
					return;
				}
			}
		}
	}
}

int main(void) {
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &maze[i][j]);
			visited[i][j] = 0;
		}
	}

	bfs();

	printf("%d", wall[n][m]);
	return 0;
}