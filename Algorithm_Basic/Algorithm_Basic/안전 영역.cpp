#include <iostream>
#include <memory.h>
using namespace std;

const int MAX = 100;

int n;
int map[MAX][MAX];
int visited[MAX][MAX];

int ans;

int d_r[4] = { -1, 0, 1, 0 };
int d_c[4] = { 0, 1, 0, -1 };

void dfs(int row, int col, int height) {
	visited[row][col] = height;

	for (int i = 0; i < 4; i++) {
		int next_row = row + d_r[i];
		int next_col = col + d_c[i];
		if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < n) {
			if (visited[next_row][next_col] != height) {
				dfs(next_row, next_col, height);
			}
		}
	}
}

void solve(int height) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] <= height) {
				visited[i][j] = height;
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] != height) {
				cnt++;
				dfs(i, j, height);
			}
		}
	}
	if (ans < cnt) {
		ans = cnt;
	}
}

int main(void) {
	cin >> n;
	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (max < map[i][j]) {
				max = map[i][j];
			}
		}
	}

	memset(visited, -1, sizeof(visited));
	for (int i = 0; i <= max; i++) {
		solve(i);
	}
	cout << ans;
	return 0;
}