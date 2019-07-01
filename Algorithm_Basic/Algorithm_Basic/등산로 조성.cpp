#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

int tc;
int n, k;
int map[8][8];
int visited[8][8];

int d_r[4] = { -1, 0, 1, 0 };
int d_c[4] = { 0, 1, 0, -1 };

stack< pair<int, int> > st_peak;

int peak;
int ans;

void find_peak() {
	peak = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] > peak) {
				peak = map[i][j];
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == peak) {
				st_peak.push(make_pair(i, j));
			}
		}
	}
}

void dfs(int row, int col, int chance, int dist) {
	visited[row][col] = 1;
	if (ans < dist) {
		ans = dist;
	}
	for (int i = 0; i < 4; i++) {
		int next_row = row + d_r[i];
		int next_col = col + d_c[i];
		if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < n) {
			if (!visited[next_row][next_col]) {
				if (map[next_row][next_col] < map[row][col]) {
					dfs(next_row, next_col, chance, dist + 1);
					visited[next_row][next_col] = 0;
				}
				else {
					if (chance) {
						int diff = map[next_row][next_col] - map[row][col];
						if (diff < k) {
							int temp = map[next_row][next_col];
							map[next_row][next_col] = map[row][col] - 1;
							dfs(next_row, next_col, 0, dist + 1);
							map[next_row][next_col] = temp;
							visited[next_row][next_col] = 0;
						}
					}
				}
			}
		}
	}
}

int main(void) {
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}

		find_peak();

		ans = 0;
		while (!st_peak.empty()) {
			memset(visited, 0, sizeof(visited));
			dfs(st_peak.top().first, st_peak.top().second, 1, 1);
			st_peak.pop();
		}
		cout << '#' << t << ' ' << ans << '\n';
	}
	return 0;
}