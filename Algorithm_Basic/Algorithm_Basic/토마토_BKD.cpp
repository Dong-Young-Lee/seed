#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int m, n;
vector< vector<int> > matrix(1000, vector<int>(1000));
queue< pair<int, int> > q;

int d_r[4] = { -1, 0, 1, 0 };
int d_c[4] = { 0, 1, 0, -1 };

int ans = 0;
void bfs() {
	while (!q.empty()) {
		int cur_row = q.front().first;
		int cur_col = q.front().second;
		int cur_type = matrix[cur_row][cur_col];
		q.pop();

		for (int i = 0; i < 4; i++) {
			int adj_row = cur_row + d_r[i];
			int adj_col = cur_col + d_c[i];
			if (adj_row >= 0 && adj_row < n && adj_col >= 0 && adj_col < m) {
				int adj_type = matrix[adj_row][adj_col];
				if (adj_type == 0) {
					q.push(make_pair(adj_row, adj_col));
					matrix[adj_row][adj_col] = cur_type + 1;
					if (ans < matrix[adj_row][adj_col]) {
						ans = matrix[adj_row][adj_col];
					}
				}
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int no_zero = 1;
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
			if (matrix[i][j] == 1) {
				q.push(make_pair(i, j));
			}
			if (no_zero == 1) {
				if (matrix[i][j] == 0) {
					no_zero = 0;
				}
			}
		}
	}
	
	if (no_zero == 1) {
		cout << 0;
		return 0;
	}

	bfs();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
	}

	cout << ans - 1;

	return 0;
}