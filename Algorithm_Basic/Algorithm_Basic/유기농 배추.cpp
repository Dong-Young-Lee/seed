#include <iostream>
#include <vector>
using namespace std;

int t, n, m, k;
int d_r[4] = {-1, 0, 1, 0};
int d_c[4] = { 0, 1, 0, -1 };

void dfs(vector< vector<int> > &matrix, vector< vector<bool> > &visited, int row, int col) {
	visited[row][col] = true;

	for (int i = 0; i < 4; i++) {
		int adj_row = row + d_r[i];
		int adj_col = col + d_c[i];
		if (adj_row >= 0 && adj_row < n && adj_col >= 0 && adj_col < m) {
			if (!visited[adj_row][adj_col] && matrix[adj_row][adj_col] == 1) {
				dfs(matrix, visited, adj_row, adj_col);
			}
		}
	}
	
}

int main(void) {
	cin >> t;
	while (t--) {
		cin >> m >> n >> k;
		vector< vector<int> > matrix(n, vector<int>(m, 0));
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			matrix[y][x] = 1;
		}

		vector< vector<bool> > visited(n, vector<bool>(m, false));
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!visited[i][j] && matrix[i][j] == 1) {
					cnt++;
					dfs(matrix, visited, i, j);
				}
			}
		}
		cout << cnt << '\n';
	}

	return 0;
}