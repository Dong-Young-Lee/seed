#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
using namespace std;

typedef struct {
	int row;
	int col;
	int dir;
	int time;
	int c_cnt;
	int d_cnt;
}info;

const int MAX = 50;
int n, m;

char map[MAX][MAX];
int visited[MAX][MAX][4][2][2];

queue<info> q;

int ans = -1;

int d_r[4] = { -1, 0, 1, 0 };
int d_c[4] = { 0, 1, 0, -1 };

void print_map() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void bfs() {
	while (!q.empty()) {
		info cur = q.front();
		q.pop();

		if (cur.c_cnt == 1 && cur.d_cnt == 1) {
			ans = cur.time;
			return;
		}

		for (int i = 0; i < 4; i++) {
			if (cur.dir != i) {
				info next = { cur.row + d_r[i], cur.col + d_c[i], i, cur.time + 1, cur.c_cnt, cur.d_cnt };
				if (next.row >= 0 && next.row < n && next.col >= 0 && next.col < m && map[next.row][next.col] != '#') {
					if (map[next.row][next.col] == 'C') {
						next.c_cnt = 1;
						if (visited[next.row][next.col][next.dir][next.c_cnt][next.d_cnt] == 0) {
							visited[next.row][next.col][next.dir][next.c_cnt][next.d_cnt] = 1;
							q.push(next);
						}
					}
					else if (map[next.row][next.col] == 'D') {
						next.d_cnt = 1;
						if (visited[next.row][next.col][next.dir][next.c_cnt][next.d_cnt] == 0) {
							visited[next.row][next.col][next.dir][next.c_cnt][next.d_cnt] = 1;
							q.push(next);
						}
					}
					else {
						if (visited[next.row][next.col][next.dir][next.c_cnt][next.d_cnt] == 0) {
							visited[next.row][next.col][next.dir][next.c_cnt][next.d_cnt] = 1;
							q.push(next);
						}
					}
				}
			}
		}
	}
}

int main(void) {
	scanf("%d %d\n", &n, &m);
	int flag = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%c\n", &map[i][j]);
			if (map[i][j] == 'S') {
				q.push({ i, j, -1, 0, 0, 0 });
			}
			else if (map[i][j] == 'C') {
				if (flag == 0) {
					map[i][j] = 'D';
				}
				flag++;
			}
		}
	}

	bfs();
	printf("%d", ans);

	return 0;
}