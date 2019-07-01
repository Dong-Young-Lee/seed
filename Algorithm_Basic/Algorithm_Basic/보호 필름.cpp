#include <iostream>
#include <memory.h>
using namespace std;

int T, t;
int d, w, k;

int map[13][20];
int temp[13][20];

int is_used[13];
int numbers[13];
int used_numbers;

int numbers_2[13];
int used_numbers_2;

int ans;
int ans_flag;

void print_map() {
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < w; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

int test() {
	if (k == 1) {
		return 1;
	}

	for (int col = 0; col < w; col++) {
		int row_pass = 0;
		for (int row = 0; row < d - k + 1; row++) {
			int cur_stat = map[row][col];
			int equal = 1;
			for (int dist = 1; dist < k; dist++) {
				int next_stat = map[row + dist][col];
				if (cur_stat != next_stat) {
					equal = 0;
					break;
				}
			}
			if (equal) {
				row_pass = 1;
				break;
			}

		}
		if (!row_pass) {
			return 0;
		}
	}
	return 1;
}

void inject() {
	for (int i = 0; i < used_numbers; i++) {
		for (int j = 0; j < w; j++) {
			temp[numbers[i]][j] = map[numbers[i]][j];
		}
	}

	for (int i = 0; i < used_numbers; i++) {
		for (int j = 0; j < w; j++) {
			map[numbers[i]][j] = numbers_2[i];
		}
	}

	int test_ret = test();
	if (test_ret) {
		ans = used_numbers;
		ans_flag = 1;
		return;
	}


	for (int i = 0; i < used_numbers; i++) {
		for (int j = 0; j < w; j++) {
			map[numbers[i]][j] = temp[numbers[i]][j];
		}
	}
}

void solve_2() {
	if (ans_flag) return;
	if (used_numbers_2 == used_numbers) {
		/*
		for (int i = 0; i < used_numbers_2; i++) {
			cout << numbers_2[i] << ' ';
		}
		cout << '\n';
		*/

		inject();

		return;
	}
	for (int i = 0; i < 2; i++) {
		numbers_2[used_numbers_2] = i;
		used_numbers_2++;
		solve_2();
		used_numbers_2--;
	}
}

void solve(int select) {
	if (ans_flag) return;
	if (used_numbers == select) {
		/*
		cout << "< ";
		for (int i = 0; i < used_numbers; i++) {
			cout << numbers[i] << ' ';
		}
		cout << ">\n";
		*/
		solve_2();

		return;
	}

	for (int i = 0; i < d; i++) {
		if (is_used[i] == 0) {
			if (used_numbers > 0) {
				if (i > numbers[used_numbers - 1]) {
					is_used[i] = 1;
					numbers[used_numbers] = i;
					used_numbers++;
					solve(select);
					is_used[i] = 0;
					used_numbers--;
				}
			}
			else {
				is_used[i] = 1;
				numbers[used_numbers] = i;
				used_numbers++;
				solve(select);
				is_used[i] = 0;
				used_numbers--;
			}
		}
	}
}

int main(void) {
	cin >> T;
	for (t = 1; t <= T; t++) {
		ans_flag = 0;
		memset(is_used, 0, sizeof(is_used));
		used_numbers = 0;
		used_numbers_2 = 0;

		cin >> d >> w >> k;
		for (int i = 0; i < d; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i <= d; i++) {
			solve(i);
		}

		cout << "#" << t << " " << ans << '\n';

	}
	return 0;
}