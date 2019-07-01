#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int T, t;
int map[4][4];

int d_r[4] = { -1, 0, 1, 0 };
int d_c[4] = { 0, 1, 0, -1 };

int numbers[7];

int visited[10][10][10][10][10][10][10];

int ans;

void dfs(int row, int col, int num) {
	numbers[num] = map[row][col];
	if (num == 6) {
		if (visited[numbers[0]][numbers[1]][numbers[2]][numbers[3]][numbers[4]][numbers[5]][numbers[6]] != t) {
			visited[numbers[0]][numbers[1]][numbers[2]][numbers[3]][numbers[4]][numbers[5]][numbers[6]] = t;
			ans++;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		int next_row = row + d_r[i];
		int next_col = col + d_c[i];
		if (next_row >= 0 && next_row < 4 && next_col >= 0 && next_col < 4) {
			dfs(next_row, next_col, num + 1);
		}
	}
}

void solve() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			dfs(i, j, 0);
		}
	}
}

int main(void) {
	scanf("%d\n", &T);
	for (t = 1; t <= T; t++) {
		ans = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				scanf("%d\n", &map[i][j]);
			}
		}

		solve();
		printf("#%d %d\n", t, ans);

	}
	return 0;
}