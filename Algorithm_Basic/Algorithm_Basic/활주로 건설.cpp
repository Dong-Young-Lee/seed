#include <iostream>
#include <memory.h>
using namespace std;

const int MAX = 20;
int test_case, T;
int n, x;

int map[MAX][MAX];
int constructed[MAX][MAX];

int row_ans;
int col_ans;
int ans;

void solve() {
	memset(constructed, 0, sizeof(constructed));
	for (int r = 0; r < n; r++) {
		int ok = 1;
		int cur_col = 0;
		while (true) {
			if (cur_col == n - 1) {
				break;
			}
			int next_col = cur_col + 1;
			
			int cur_val = map[r][cur_col];
			int next_val = map[r][next_col];

			if (cur_val == next_val) {
				cur_col = next_col;
				continue;
			}
			else if (cur_val+1 == next_val) {
				if (cur_col - x + 1 < 0) {
					ok = 0;
					break;
				}
				else {
					int can_construct = 1;
					for (int i = 0; i < x; i++) {
						if (constructed[r][cur_col - i] == 1) {
							can_construct = 0;
							break;
						}
					}
					if (can_construct) {
						int same = 1;
						for (int i = 1; i < x; i++) {
							if (cur_val != map[r][cur_col - i]) {
								same = 0;
								break;
							}
						}
						if (same) {
							for (int i = 0; i < x; i++) {
								constructed[r][cur_col - i] = 1;
							}
							cur_col = next_col;
							continue;
						}
						else {
							ok = 0;
							break;
						}
					}
					else {
						ok = 0;
						break;
					}
				}
			}
			else if (cur_val-1 == next_val) {
				if (cur_col + x - 1 >= n) {
					ok = 0;
					break;
				}
				else {
					int can_construct = 1;
					for (int i = 0; i < x; i++) {
						if (constructed[r][next_col + i] == 1) {
							can_construct = 0;
							break;
						}
					}
					if (can_construct) {
						int same = 1;
						for (int i = 1; i < x; i++) {
							if (next_val != map[r][next_col + i]) {
								same = 0;
								break;
							}
						}
						if (same) {
							for (int i = 0; i < x; i++) {
								constructed[r][next_col + i] = 1;
							}
							cur_col += x;
							continue;
						}
						else {
							ok = 0;
							break;
						}
					}
					else {
						ok = 0;
						break;
					}
				}
			}
			else {
				ok = 0;
				break;
			}
		}
		if (ok) {
			row_ans++;
		}
	}

	memset(constructed, 0, sizeof(constructed));

	for (int c = 0; c < n; c++) {
		int ok = 1;
		int cur_row = 0;
		while (true) {
			if (cur_row == n - 1) {
				break;
			}
			int next_row = cur_row + 1;

			int cur_val = map[cur_row][c];
			int next_val = map[next_row][c];

			if (cur_val == next_val) {
				cur_row = next_row;
				continue;
			}
			else if (cur_val+1 == next_val) {
				if (cur_row - x + 1 < 0) {
					ok = 0;
					break;
				}
				else {
					int can_construct = 1;
					for (int i = 0; i < x; i++) {
						if (constructed[cur_row - i][c] == 1) {
							can_construct = 0;
							break;
						}
					}
					if (can_construct) {
						int same = 1;
						for (int i = 1; i < x; i++) {
							if (cur_val != map[cur_row - i][c]) {
								same = 0;
								break;
							}
						}
						if (same) {
							for (int i = 0; i < x; i++) {
								constructed[cur_row - i][c] = 1;
							}
							cur_row = next_row;
							continue;
						}
						else {
							ok = 0;
							break;
						}
					}
					else {
						ok = 0;
						break;
					}
				}
			}
			else if (cur_val-1 == next_val) {
				if (cur_row + x - 1 >= n) {
					ok = 0;
					break;
				}
				else {
					int can_construct = 1;
					for (int i = 0; i < x; i++) {
						if (constructed[next_row + i][c] == 1) {
							can_construct = 0;
							break;
						}
					}
					if (can_construct) {
						int same = 1;
						for (int i = 1; i < x; i++) {
							if (next_val != map[next_row + i][c]) {
								same = 0;
								break;
							}
						}
						if (same) {
							for (int i = 0; i < x; i++) {
								constructed[next_row + i][c] = 1;
							}
							cur_row += x;
							continue;
						}
						else {
							ok = 0;
							break;
						}
					}
					else {
						ok = 0;
						break;
					}
				}
			}
			else {
				ok = 0;
				break;
			}
		}
		if (ok) {
			col_ans++;
		}
	}
}

int main(void) {
	cin >> T;
	for (test_case = 1; test_case <= T; test_case++) {
		row_ans = 0;
		col_ans = 0;

		cin >> n >> x;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}

		solve();

		cout << "#" << test_case << " " << row_ans + col_ans << "\n";
	}

	return 0;
}