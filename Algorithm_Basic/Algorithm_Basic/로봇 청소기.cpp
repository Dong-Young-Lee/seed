#include <iostream>
#include <vector>
using namespace std;

// 2 : ·Îº¿ / Ã»¼ÒÇÑ Ä­
// 0 : ºó Ä­
// 1 : º®

// d == 0, ºÏ
// d == 1, µ¿
// d == 2, ³²
// d == 3, ¼­

int n, m;
int r, c, d;
int d_r[4] = { -1, 0, 1, 0 };
int d_c[4] = { 0, 1, 0, -1 };
int cnt = 1;

int ans_print = 0;

void dfs(vector< vector<int> > &matrix, int row, int col, int cur_d) {
	matrix[row][col] = 2;


	int next_d;
	for (int i = 1; i < 5; i++) {
		next_d = cur_d - i;
		if (next_d < 0) {
			next_d += 4;
		}

		int next_row = row + d_r[next_d];
		int next_col = col + d_c[next_d];
		if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < m) {
			if (matrix[next_row][next_col] == 0) {
				cnt++;
				dfs(matrix, next_row, next_col, next_d);
			}
		}
	}

	if (ans_print == 0) {
		int back_d = cur_d - 2;
		if (back_d < 0) {
			back_d += 4;
		}

		int back_row = row + d_r[back_d];
		int back_col = col + d_c[back_d];
		if (back_row >= 0 || back_row < n || back_col >= 0 || back_col < m) {
			if (matrix[back_row][back_col] == 1) {
				cout << cnt;
				ans_print = 1;
			}
			else {
				dfs(matrix, back_row, back_col, cur_d);
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	vector< vector<int> > matrix(n, vector<int>(m));
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
		}
	}
	
	dfs(matrix, r, c, d);
	if (ans_print == 0) {
		cout << cnt;
	}

	return 0;
}

