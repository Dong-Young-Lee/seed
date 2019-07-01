#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

typedef struct {
	int row;
	int col;
}info;

const int MAX = 500;
int r, c;
char map[MAX][MAX];

int d_r[4] = { -1, 0, 1, 0 };
int d_c[4] = { 0, 1, 0, -1 };

info sheep[MAX * MAX];
int sheep_cnt;

int main(void) {
	scanf("%d %d\n", &r, &c);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf("%c\n", &map[i][j]);
			if (map[i][j] == 'S') {
				sheep[sheep_cnt++] = { i, j };
			}
		}
	}

	for (int i = 0; i < sheep_cnt; i++) {
		for (int j = 0; j < 4; j++) {
			int next_row = sheep[i].row + d_r[j];
			int next_col = sheep[i].col + d_c[j];
			if (next_row >= 0 && next_row < r && next_col >= 0 && next_col < c) {
				if (map[next_row][next_col] == '.') {
					map[next_row][next_col] = 'D';
				}
				else if (map[next_row][next_col] == 'W') {
					printf("0");
					return 0;
				}
			}
		}
	}

	printf("1\n");
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}

	return 0;
}