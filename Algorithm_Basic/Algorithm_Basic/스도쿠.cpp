#include <iostream>
#include <memory.h>
using namespace std;

typedef struct {
	int row;
	int col;
	int pos;
}info;

const int MAX = 9;
int map[MAX][MAX];

int numbers[MAX * MAX];
int used_numbers;


int is_used[MAX * MAX];
info zero_arr[MAX * MAX];
int zero_cnt = 0;

int ans_flag = 0;

int is_valid(int pos, int num) {
	int check[10] = { 0, };
	int first_row = (pos / 3) * 3;
	int first_col = (pos % 3) * 3;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (map[first_row + i][first_col + j] != 0) {
				check[map[first_row + i][first_col + j]]++;
			}
		}
	}

	check[num]++;
	for (int i = 1; i < 10; i++) {
		if (check[i] > 1) {
			return 0;
		}
	}

	return 1;
}

void solve() {
	if (ans_flag) return;

	if (used_numbers == zero_cnt) {
		/*
		for (int i = 0; i < used_numbers; i++) {
			cout << numbers[i] << ' ';
		}
		cout << '\n';
		*/
		
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << map[i][j] << ' ';
			}
			cout << '\n';
		}
		ans_flag = 1;
		
		return;
	}

	for (int i = 1; i < 10; i++) {
		int cur_row = zero_arr[used_numbers].row;
		int cur_col = zero_arr[used_numbers].col;
		int cur_pos = zero_arr[used_numbers].pos;

		// col
		int check[10] = { 0, };
		for (int j = 0; j < 9; j++) {
			if (map[cur_row][j] != 0) {
				check[map[cur_row][j]]++;
			}
		}
		check[i]++;
		int col_can = 1;
		for (int j = 1; j < 10; j++) {
			if (check[j] > 1) {
				col_can = 0;
				break;
			}
		}
		if (!col_can) continue;

		// row
		memset(check, 0, sizeof(check));
		for (int j = 0; j < 9; j++) {
			if (map[j][cur_col] != 0) {
				check[map[j][cur_col]]++;
			}
		}
		check[i]++;
		int row_can = 1;
		for (int j = 1; j < 10; j++) {
			if (check[j] > 1) {
				row_can = 0;
				continue;
			}
		}
		if (!row_can) continue;

		// pos
		int can_go = is_valid(cur_pos, i);
		if (!can_go) {
			continue;
		}

		numbers[used_numbers] = i;
		used_numbers++;
		map[cur_row][cur_col] = i;
		solve();
		used_numbers--;
		map[cur_row][cur_col] = 0;
		if (ans_flag) return;
	}
}

int main(void) {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				zero_arr[zero_cnt].row = i;
				zero_arr[zero_cnt].col = j;
				if (i < 3 && j < 3) {
					zero_arr[zero_cnt].pos = 0;
				}
				else if (i < 3 && j >= 3 && j < 6) {
					zero_arr[zero_cnt].pos = 1;
				}
				else if (i < 3 && j >= 6 && j < 9) {
					zero_arr[zero_cnt].pos = 2;
				}
				else if (i >= 3 && i < 6 && j < 3) {
					zero_arr[zero_cnt].pos = 3;
				}
				else if (i >= 3 && i < 6 && j >= 3 && j < 6) {
					zero_arr[zero_cnt].pos = 4;
				}
				else if (i >= 3 && i < 6 && j >= 6 && j < 9) {
					zero_arr[zero_cnt].pos = 5;
				}
				else if (i >= 6 && i < 9 && j < 3) {
					zero_arr[zero_cnt].pos = 6;
				}
				else if (i >= 6 && i < 9 && j >= 3 && j < 6) {
					zero_arr[zero_cnt].pos = 7;
				}
				else if (i >= 6 && i < 9 && j >= 6 && j < 9) {
					zero_arr[zero_cnt].pos = 8;
				}
				zero_cnt++;
			}
		}
	}

	solve();

	return 0;
}