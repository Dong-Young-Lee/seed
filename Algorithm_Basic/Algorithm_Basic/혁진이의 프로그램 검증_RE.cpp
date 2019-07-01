#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <string.h>
using namespace std;

typedef struct {
	int row;
	int col;
	int dir;
	int mem;
}info;

const int MAX = 20;

int tc, t, r, c;
char map[MAX][MAX];
int visited[MAX][MAX][4][16];

int d_r[4] = { -1, 0, 1, 0 };
int d_c[4] = { 0, 1, 0, -1 };

int yes_flag;

void bfs() {
	queue<info> q;
	q.push({ 0, 0, 1, 0 });
	visited[0][0][1][0] = t;

	while (!q.empty()) {
		int cur_row = q.front().row;
		int cur_col = q.front().col;
		int cur_dir = q.front().dir;
		int cur_mem = q.front().mem;
		q.pop();

		char instruction = map[cur_row][cur_col];

		int next_row;
		int next_col;
		int next_dir = cur_dir;
		int next_mem = cur_mem;

		if (instruction == '<') {
			next_dir = 3;
		}
		else if (instruction == '>') {
			next_dir = 1;
		}
		else if (instruction == '^') {
			next_dir = 0;
		}
		else if (instruction == 'v') {
			next_dir = 2;
		}
		else if (instruction == '_') {
			if (cur_mem == 0) {
				next_dir = 1;
			}
			else {
				next_dir = 3;
			}
		}
		else if (instruction == '|') {
			if (cur_mem == 0) {
				next_dir = 2;
			}
			else {
				next_dir = 0;
			}
		}
		else if (instruction == '|') {
			if (cur_mem == 0) {
				next_dir = 2;
			}
			else {
				next_dir = 0;
			}
		}
		else if (instruction == '@') {
			yes_flag = 1;
			while (!q.empty()) {
				q.pop();
			}
			break;
		}
		else if (instruction >= '0' && instruction <= '9') {
			next_mem = instruction - '0';
		}
		else if (instruction == '+') {
			next_mem = (cur_mem + 1) % 16;
		}
		else if (instruction == '-') {
			next_mem = (cur_mem - 1 + 16) % 16;
		}

		if (instruction == '?') {
			for (int i = 0; i < 4; i++) {
				next_row = (cur_row + d_r[i] + r) % r;
				next_col = (cur_col + d_c[i] + c) % c;

				if (visited[next_row][next_col][i][next_mem] != t) {
					visited[next_row][next_col][i][next_mem] = t;
					q.push({ next_row, next_col, i, next_mem });
				}

			}
		}
		else {
			next_row = (cur_row + d_r[next_dir] + r) % r;
			next_col = (cur_col + d_c[next_dir] + c) % c;

			if (visited[next_row][next_col][next_dir][next_mem] != t) {
				visited[next_row][next_col][next_dir][next_mem] = t;
				q.push({ next_row, next_col, next_dir, next_mem });
			}
		}
	}
}

int main(void) {
	scanf("%d\n", &tc);
	for (t = 1; t <= tc; t++) {
		yes_flag = 0;

		scanf("%d %d\n", &r, &c);
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				scanf("%c", &map[i][j]);
			}
			scanf("\n");
		}

		bfs();

		if (yes_flag) {
			printf("#%d YES\n", t);
		}
		else {
			printf("#%d NO\n", t);
		}
	}

	return 0;
}