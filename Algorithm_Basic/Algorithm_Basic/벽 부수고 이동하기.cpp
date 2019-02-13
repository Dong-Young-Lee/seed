// 다시
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <tuple>

using namespace std;
int n, m;
int maze[1001][1001];
// movement[i][j][k]
// k = 0 : 
int movement[1001][1001][2];

int d_row[4] = {-1, 0, 1, 0};
int d_col[4] = { 0, 1, 0, -1 };

void bfs() {
	queue< tuple<int, int, int> > q;
	movement[1][1][0] = 1;
	q.push(make_tuple(1, 1, 0));

	while (!q.empty()) {
		int cur_row, cur_col, cur_crashed;
		tie(cur_row, cur_col, cur_crashed) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int adj_row = cur_row + d_row[i];
			int adj_col = cur_col + d_col[i];
			if (adj_row >= 1 && adj_row <= n &&
				adj_col >= 1 && adj_col <= m) {
				// 인접한 위치가 벽이 아니고, 이동하지 않았으면
				if (maze[adj_row][adj_col] == 0 &&
					movement[adj_row][adj_col][cur_crashed] == 0) {
					q.push(make_tuple(adj_row, adj_col, cur_crashed));
					movement[adj_row][adj_col][cur_crashed] = movement[cur_row][cur_col][cur_crashed] + 1;
				}
				// 인접한 위치가 벽이고, 벽을 부순적이 없고, 벽을 부순 자리에 이동한 적이 없으면
				if (maze[adj_row][adj_col] == 1 &&
					cur_crashed == 0 &&
					movement[adj_row][adj_col][cur_crashed + 1] == 0) {
					q.push(make_tuple(adj_row, adj_col, cur_crashed + 1));
					movement[adj_row][adj_col][cur_crashed + 1] = movement[cur_row][cur_col][cur_crashed] + 1;
				}
			}
		}
	}
}

void print_ans() {
	if (movement[n][m][0] != 0 && movement[n][m][1] != 0) {
		printf("%d\n", min(movement[n][m][0], movement[n][m][1]));
	}
	else if (movement[n][m][0] != 0) {
		printf("%d\n", movement[n][m][0]);
	}
	else if (movement[n][m][1] != 0) {
		printf("%d\n", movement[n][m][1]);
	}
	else {
		printf("-1\n");
	}
}

int main(void) {
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &maze[i][j]);
		}
	}

	bfs();

	print_ans();
	
	return 0;
}