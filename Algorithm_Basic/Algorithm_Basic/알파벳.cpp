#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

const int MAX = 20;
int r, c;
char map[MAX][MAX];

int d_r[4] = { -1, 0, 1, 0 };
int d_c[4] = { 0, 1, 0, -1 };

int cnt;
int ans;

int is_used[26];

void dfs(int row, int col) {
	is_used[map[row][col] - 'A'] = 1;
	cnt++;
	if (ans < cnt) {
		ans = cnt;
	}
	for (int i = 0; i < 4; i++) {
		int next_row = row + d_r[i];
		int next_col = col + d_c[i];
		if (next_row >= 0 && next_row < r && next_col >= 0 && next_col < c) {
			if (is_used[map[next_row][next_col] - 'A'] == 0) {
				dfs(next_row, next_col);
			}
		}
	}
	cnt--;
	is_used[map[row][col] - 'A'] = 0;
}

int main(void) {
	scanf("%d %d\n", &r, &c);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf("%c", &map[i][j]);
		}
		scanf("\n");
	}

	dfs(0, 0);
	printf("%d", ans);
	return 0;
}