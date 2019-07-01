#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
using namespace std;

typedef struct {
	int row;
	int col;
}info;

const int MAX = 1000;
int n, m, p;
int map[MAX][MAX];
int movement[10];

queue<info> q[10];

int d_r[4] = { -1, 0, 1, 0 };
int d_c[4] = { 0, 1, 0, -1 };

int ans[10];

void print_map() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void bfs() {
	while (true) {
		for (int i = 1; i <= p; i++) {
			for (int j = 0; j < movement[i]; j++) {
				int q_size = q[i].size();
				if (q_size == 0) break;
				for (int k = 0; k < q_size; k++) {
					info cur = q[i].front();
					q[i].pop();

					for (int d = 0; d < 4; d++) {
						info next = { cur.row + d_r[d], cur.col + d_c[d] };
						if (next.row >= 0 && next.row < n && next.col >= 0 && next.col < m) {
							if (map[next.row][next.col] == 0) {
								map[next.row][next.col] = i;
								q[i].push(next);
							}
						}
					}
				}
			}
		}
		int go = 0;
		for (int i = 1; i <= p; i++) {
			if (!q[i].empty()) {
				go = 1;
				break;
			}
		}
		if (!go) break;
	}
}

void find_ans() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int num = map[i][j];
			ans[num]++;
		}
	}
}

int main(void) {
	scanf("%d %d %d\n", &n, &m, &p);
	for (int i = 1; i <= p; i++) {
		scanf("%d\n", &movement[i]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char input;
			scanf("%c\n", &input);
			if (input >= '1' && input <= '9') {
				int num = input - '0';
				map[i][j] = num;
				q[num].push({ i, j });
			}
			else if (input == '.') {
				map[i][j] = 0;
			}
			else {
				map[i][j] = -1;
			}
		}
	}

	bfs();
	find_ans();

	for (int i = 1; i <= p; i++) {
		printf("%d ", ans[i]);
	}

	return 0;
}