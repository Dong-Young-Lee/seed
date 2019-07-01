#include <iostream>
using namespace std;

const int MAX = 10;
int map[MAX][MAX];

int is_used[5];
int used_numbers;

int one;
int ans = 2147483647;

void modify_paper(int row, int col, int t, int draw) {
	int paper_size = t + 1;

	if (draw == 1) {
		for (int r = row; r < row + paper_size; r++) {
			for (int c = col; c < col + paper_size; c++) {
				map[r][c] = t + 2;
			}
		}
		one -= ((paper_size)*(paper_size));
	}
	else {
		for (int r = row; r < row + paper_size; r++) {
			for (int c = col; c < col + paper_size; c++) {
				map[r][c] = 1;
			}
		}
		one += ((paper_size)*(paper_size));
	}
}

int is_valid(int row, int col, int t) {
	int ret = 1;
	int max_row = row + t;
	int max_col = col + t;
	if (max_row < MAX && max_col < MAX) {
		for (int r = row; r <= max_row; r++) {
			for (int c = col; c <= max_col; c++) {
				if (map[r][c] != 1) {
					ret = 0;
					break;
				}
			}
			if (ret == 0) {
				break;
			}
		}
	}
	else {
		ret = 0;
	}
	return ret;
}

void dfs(int row) {
	if (ans <= used_numbers) return;

	if (one == 0) {
		if (ans > used_numbers) {
			ans = used_numbers;
		}
		return;
	}

	for (int r = row; r < MAX; r++) {
		for (int c = 0; c < MAX; c++) {
			if (map[r][c] == 1) {
				int flag = 0;
				for (int t = 0; t < 5; t++) {
					if (is_used[t] > 0) {
						if (is_valid(r, c, t)) {
							is_used[t]--;
							modify_paper(r, c, t, 1);
							used_numbers++;
							flag = 1;
							dfs(r);
							flag = 0;
							used_numbers--;
							modify_paper(r, c, t, 0);
							is_used[t]++;
						}
					}
				}
				if (flag == 0) {
					return;
				}
			}
		}
	}

}

int main(void) {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				one++;
			}
		}
	}

	if (one == 0) {
		cout << 0;
		return 0;
	}
	else if (one == 100) {
		cout << 4;
		return 0;
	}

	for (int i = 0; i < 5; i++) {
		is_used[i] = 5;
	}
	is_used[4]--;

	dfs(0);

	if (ans == 2147483647) {
		cout << -1;
	}
	else {
		cout << ans;
	}
	return 0;
}