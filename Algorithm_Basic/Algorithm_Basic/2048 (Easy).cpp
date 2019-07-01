#include <iostream>
#include <algorithm>
using namespace std;

int n;
int board[20][20];
int board_copy[20][20];
int numbers[5];
int used_numbers;

int d_r[4] = { -1, 1, 0, 0 };
int d_c[4] = { 0, 0, -1, 1 };

int ans;

void find_ans() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (ans < board[i][j]) {
				ans = board[i][j];
			}
		}
	}
}

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			board[i][j] = board_copy[i][j];
		}
	}
}

void tilt_board(int dir) {
	int merged[20][20] = { 0, };
	if (dir == 0) { // ╩С
		for (int col = 0; col < n; col++) {
			for (int row = 1; row < n; row++) {
				int empty = 0;
				int merged_flag = 0;
				for (int dist = 1; dist <= row; dist++) {
					int next_row = row - dist;
					if (board[next_row][col] != 0) {
						if (board[next_row][col] == board[row][col] && merged[next_row][col] == 0) {
							board[next_row][col] *= 2;
							board[row][col] = 0;
							merged[next_row][col] = 1;
							merged_flag = 1;
						}
						break;
					}
					empty++;
				}
				if (merged_flag) continue;

				if (empty > 0) {
					board[row - empty][col] = board[row][col];
					board[row][col] = 0;
				}
			}
		}
	}
	else if (dir == 1) { // го
		for (int col = 0; col < n; col++) {
			for (int row = n - 2; row >= 0; row--) {
				int empty = 0;
				int merged_flag = 0;
				for (int dist = 1; dist <= n - row - 1; dist++) {
					int next_row = row + dist;
					if (board[next_row][col] != 0) {
						if (board[next_row][col] == board[row][col] && merged[next_row][col] == 0) {
							board[next_row][col] *= 2;
							board[row][col] = 0;
							merged[next_row][col] = 1;
							merged_flag = 1;
						}
						break;
					}
					empty++;
				}
				if (merged_flag) continue;

				if (empty > 0) {
					board[row + empty][col] = board[row][col];
					board[row][col] = 0;
				}
			}
		}
	}
	else if (dir == 2) { // аб
		for (int row = 0; row < n; row++) {
			for (int col = 1; col < n; col++) {
				int empty = 0;
				int merged_flag = 0;
				for (int dist = 1; dist <= col; dist++) {
					int next_col = col - dist;
					if (board[row][next_col] != 0) {
						if (board[row][next_col] == board[row][col] && merged[row][next_col] == 0) {
							board[row][next_col] *= 2;
							board[row][col] = 0;
							merged[row][next_col] = 1;
							merged_flag = 1;
						}
						break;
					}
					empty++;
				}
				if (merged_flag) continue;

				if (empty > 0) {
					board[row][col - empty] = board[row][col];
					board[row][col] = 0;
				}
			}
		}
	}
	else { // ©Л
		for (int row = 0; row < n; row++) {
			for (int col = n - 2; col >= 0; col--) {
				int empty = 0;
				int merged_flag = 0;
				for (int dist = 1; dist <= n - col - 1; dist++) {
					int next_col = col + dist;
					if (board[row][next_col] != 0) {
						if (board[row][next_col] == board[row][col] && merged[row][next_col] == 0) {
							board[row][next_col] <<= 1;
							board[row][col] = 0;
							merged[row][next_col] = 1;
							merged_flag = 1;
						}
						break;
					}
					empty++;
				}
				if (merged_flag) continue;

				if (empty > 0) {
					board[row][col + empty] = board[row][col];
					board[row][col] = 0;
				}
			}
		}
	}
}

void set_order() {
	if (used_numbers == 5) {
		init();
		for (int i = 0; i < 5; i++) {
			tilt_board(numbers[i]);
		}
		find_ans();
		return;
	}

	for (int i = 0; i < 4; i++) {
		numbers[used_numbers] = i;
		used_numbers++;
		set_order();
		used_numbers--;
	}
}

void print_board() {
	cout << "<BOARD>\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout <<  board[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board_copy[i][j];
		}
	}

	set_order();
	cout << ans;
	return 0;
}