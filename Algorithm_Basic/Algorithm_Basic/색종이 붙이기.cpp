#include <iostream>
using namespace std;

const int MAX = 10;
int map[MAX][MAX];

int one_number;
int is_used[5];
int cnt;
int ans = 2147483647;

int test;

void print_map() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void change_paper(int r, int c, int p, int mode) {
	int paper_size = p + 1;
	if (mode == 1) {
		for (int i = r; i < r + paper_size; i++) {
			for (int j = c; j < c + paper_size; j++) {
				map[i][j] = paper_size + 1;
			}
		}
		one_number -= (paper_size * paper_size);
	}
	else {
		for (int i = r; i < r + paper_size; i++) {
			for (int j = c; j < c + paper_size; j++) {
				map[i][j] = 1;
			}
		}
		one_number += (paper_size * paper_size);
	}
}

int is_valid(int r, int c, int p) {
	int ok = 1;
	int paper_size = p + 1;

	for (int i = r; i < r + paper_size; i++) {
		for (int j = c; j < c + paper_size; j++) {
			if (map[i][j] != 1) {
				ok = 0;
				break;
			}
		}
		if (!ok) break;
	}

	return ok;
}

void solve(int row) {
	// test++;
	// print_map();

	if (cnt > ans) {
		return;
	}

	if (one_number == 0) {
		if (ans > cnt) {
			ans = cnt;
		}
		return;
	}

	for (int r = row; r < MAX; r++) {
		for (int c = 0; c < MAX; c++) {
			if (map[r][c] == 1) {
				int ok_flag = 0;
				for (int p = 4; p >= 0; p--) {
					if (is_used[p] > 0) {
						if (r + p < MAX && c + p < MAX) {
							if (is_valid(r, c, p)) {
								is_used[p]--;
								change_paper(r, c, p, 1);
								cnt++;
								ok_flag = 1;
								solve(r);
								ok_flag = 0;
								is_used[p]++;
								change_paper(r, c, p, 0);
								cnt--;
							}
						}
					}
				}
				if (ok_flag == 0) {
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
				one_number++;
			}
		}
	}

	for (int i = 0; i < 5; i++) {
		is_used[i] = 5;
	}
	is_used[4]--;

	if (one_number == 0) {
		cout << 0;
	}
	else {
		solve(0);
		if (ans == 2147483647) {
			cout << -1;
		}
		else {
			cout << ans;
		}
	}
	return 0;
}