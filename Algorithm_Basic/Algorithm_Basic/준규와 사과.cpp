#include <iostream>
using namespace std;

const int MAX = 5;

int k;
int map[MAX][MAX];
int visited[MAX][MAX];
int d_r[4] = { -1,0,1,0 };
int d_c[4] = { 0,1,0,-1 };

int total_cnt;
int ans;

void dfs(int row, int col, int cnt) {
	if (row == MAX - 1 && col == MAX - 1 && cnt == total_cnt) {
		ans++;
		return;
	}
	
	visited[row][col] = 1;

	for (int i = 0; i < 4; i++) {
		int next_row = row + d_r[i];
		int next_col = col + d_c[i];
		if (next_row >= 0 && next_row < MAX && next_col >= 0 && next_col < MAX) {
			if (visited[next_row][next_col] == 0 && map[next_row][next_col] == 0) {
				dfs(next_row, next_col, cnt+1);
				visited[next_row][next_col] = 0;
			}
		}
	}
}

int main(void) {
	cin >> k;
	for (int i = 0; i < k; i++) {
		int r, c;
		cin >> r >> c;
		map[r - 1][c - 1] = 1;
	}
	total_cnt = 25 - k;

	dfs(0, 0, 1);

	cout << ans;

	return 0;
}