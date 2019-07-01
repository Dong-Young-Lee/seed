#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

const int MAX = 20;
int r, c;
char map[MAX][MAX];
int visited[26];

int d_r[4] = { -1, 0, 1, 0 };
int d_c[4] = { 0, 1, 0, -1 };

int ans;

void dfs(int row, int col, int len) {
	if (ans < len) {
		ans = len;
	}

	visited[map[row][col] - 'A'] = 1;
	
	for (int i = 0; i < 4; i++) {
		int next_row = row + d_r[i];
		int next_col = col + d_c[i];
		if (next_row >= 0 && next_row < r && next_col >= 0 && next_col < c) {
			if (visited[map[next_row][next_col] - 'A'] == 0) {
				dfs(next_row, next_col, len + 1);
				visited[map[next_row][next_col] - 'A'] = 0;
			}
		}
	}
}

int main(void) {
	scanf("%d %d\n", &r, &c);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf("%c\n", &map[i][j]);
		}
	}

	dfs(0, 0, 1);

	printf("%d", ans);

	return 0;
}