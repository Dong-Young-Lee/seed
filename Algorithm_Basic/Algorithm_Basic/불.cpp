#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
using namespace std;

typedef struct {
	int row;
	int col;
	int type;
}info;

const int MAX = 1000;

int test_case, T;
int w, h;
char map[MAX][MAX];

queue<info> q;

int d_r[4] = { -1, 0, 1, 0 };
int d_c[4] = { 0, 1, 0, -1 };

int time;
int impossible;
int live;
int ans_flag;

void print_map() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void bfs() {
	while (!q.empty()) {
		// print_map();
		int q_size = q.size();
		for (int j = 0; j < q_size; j++) {
			info cur = q.front();
			q.pop();

			if (cur.type == 0) {
				for (int i = 0; i < 4; i++) {
					int next_row = cur.row + d_r[i];
					int next_col = cur.col + d_c[i];
					if (next_row >= 0 && next_row < h && next_col >= 0 && next_col < w) {
						if (map[next_row][next_col] == '.' || map[next_row][next_col] == '@') {
							if (map[next_row][next_col] == '@') {
								live--;
							}
							map[next_row][next_col] = '*';
							q.push({ next_row, next_col, 0 });
						}
					}
				}
			}
			else {
				for (int i = 0; i < 4; i++) {
					int next_row = cur.row + d_r[i];
					int next_col = cur.col + d_c[i];
					if (next_row >= 0 && next_row < h && next_col >= 0 && next_col < w) {
						if (map[next_row][next_col] == '.') {
							map[next_row][next_col] = '@';
							q.push({ next_row, next_col, 1 });
							live++;
						}
					}
					else {
						impossible = 0;
						ans_flag = 1;
						break;
					}
				}
			}

			if (ans_flag) {
				break;
			}

		}

		if (ans_flag) {
			break;
		}

		if (live < 1) {
			impossible = 1;
			return;
		}

		time++;
	}

}

int main(void) {
	scanf("%d\n", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		impossible = 0;
		time = 1;
		live = 1;
		ans_flag = 0;

		while (!q.empty()) {
			q.pop();
		}

		scanf("%d %d\n", &w, &h);
		info start;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf("%c\n", &map[i][j]);
				if (map[i][j] == '@') {
					start = { i, j, 1 };
				}
				else if (map[i][j] == '*') {
					q.push({ i, j, 0 });
				}
			}
		}
		q.push(start);

		bfs();

		if (impossible || !ans_flag) {
			printf("IMPOSSIBLE\n");
		}
		else {
			printf("%d\n", time);
		}
	}

	return 0;
}