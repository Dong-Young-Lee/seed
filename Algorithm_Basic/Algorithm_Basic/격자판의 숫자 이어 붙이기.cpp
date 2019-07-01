#include <iostream>
#include <string>
#include <set>
using namespace std;

const int MAX = 4;

int tc;
int map[MAX][MAX];

int d_r[4] = { -1, 0, 1, 0 };
int d_c[4] = { 0, 1, 0, -1 };

set<string> numbers;

void dfs(int row, int col, int move, string route) {
	if (move == 6) {
		numbers.insert(route);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int next_row = row + d_r[i];
		int next_col = col + d_c[i];
		if (next_row >= 0 && next_row < MAX && next_col >= 0 && next_col < MAX) {
			dfs(next_row, next_col, move + 1, route + to_string(map[next_row][next_col]));

		}
	}
}

int main(void) {
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				cin >> map[i][j];
			}
		}
		numbers.clear();
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				dfs(i, j, 0, to_string(map[i][j]));
			}
		}
		cout << '#' << t << ' ' << numbers.size() << '\n';
	}

	return 0;
}