#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
using namespace std;

typedef struct {
	int row;
	int col;
}info;

const int MAX = 1500;
int r, c;
char map[MAX][MAX];

info swan[2];
int swan_num;

queue<info> water_q;
queue<info> water_next_q;
int w_visited[MAX][MAX];
queue<info> swan_q;
queue<info> swan_next_q;
int s_visited[MAX][MAX];

int d_r[4] = { -1, 0, 1, 0 };
int d_c[4] = { 0, 1, 0, -1 };

int ans;

void print_map() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void bfs() {
	int time = 0;
	s_visited[swan_q.front().row][swan_q.front().col] = 1;
	while (true) {
		 //printf("time : %d\n", time);
		 //print_map();

		int waiting_num = swan_next_q.size();
		for (int i = 0; i < waiting_num; i++) {
			if (map[swan_next_q.front().row][swan_next_q.front().col] == '.') {
				swan_q.push(swan_next_q.front());
				swan_next_q.pop();
			}
			else {
				swan_next_q.push(swan_next_q.front());
				swan_next_q.pop();
			}
		}

		while (!swan_q.empty()) {
			info cur = swan_q.front();
			swan_q.pop();

			for (int i = 0; i < 4; i++) {
				info next = { cur.row + d_r[i], cur.col + d_c[i] };

				if (next.row == swan[1].row && next.col == swan[1].col) {
					ans = time;
					return;
				}

				if (next.row >= 0 && next.row < r && next.col >= 0 && next.col < c) {
					if (map[next.row][next.col] == '.' && s_visited[next.row][next.col] == 0) {
						s_visited[next.row][next.col] = 1;
						swan_q.push(next);
					}
					else if (map[next.row][next.col] == 'X' && s_visited[next.row][next.col] == 0) {
						s_visited[next.row][next.col] = 1;
						swan_next_q.push(next);
					}
				}
			}
		}

		while (!water_next_q.empty()) {
			water_q.push(water_next_q.front());
			water_next_q.pop();
		}

		while (!water_q.empty()) {
			info cur = water_q.front();
			water_q.pop();

			for (int i = 0; i < 4; i++) {
				info next = { cur.row + d_r[i], cur.col + d_c[i] };
				if (next.row >= 0 && next.row < r && next.col >= 0 && next.col < c) {
					if (map[next.row][next.col] == 'X' && w_visited[next.row][next.col] == 0) {
						w_visited[next.row][next.col] = 1;
						map[next.row][next.col] = '.';
						water_next_q.push(next);
					}
				}
			}
		}

		time++;
	}
}

int main(void) {
	scanf("%d %d\n", &r, &c);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf("%c\n", &map[i][j]);
			if (map[i][j] == 'L') {
				if (swan_num == 0) {
					swan[swan_num] = { i, j };
					swan_q.push(swan[swan_num++]);
					map[i][j] = '.';
					water_q.push({ i, j });
				}
				else {
					swan[swan_num] = { i, j };
					map[i][j] = '.';
					water_q.push({ i, j });
				}
			}
			else if (map[i][j] == '.') {
				water_q.push({ i, j });
			}
		}
	}

	bfs();

	printf("%d", ans);

	return 0;
}