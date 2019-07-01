#include <iostream>
using namespace std;

typedef struct {
	int num;
	char color;
}info;

const int MAX = 10;

int n;

info base_map[5][5];
info added_map[MAX][4][4];

int is_used[MAX];
int numbers[MAX];
int used_numbers;

int numbers_2[MAX];
int used_numbers_2;

int numbers_3[MAX];
int used_numbers_3;

int d_r[4] = { 0, 0, 1, 1 };
int d_c[4] = { 0, 1, 0, 1 };

info temp[4][4];
int ans = -225;

void init() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			base_map[i][j].num = 0;
			base_map[i][j].color = 'W';
		}
	}
}


void print_base_map() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << base_map[i][j].num << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << base_map[i][j].color << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

void add_map(int index, int pos) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			base_map[i + d_r[pos]][j + d_c[pos]].num += temp[i][j].num;
			if (base_map[i + d_r[pos]][j + d_c[pos]].num < 0) {
				base_map[i + d_r[pos]][j + d_c[pos]].num = 0;
			}
			else if (base_map[i + d_r[pos]][j + d_c[pos]].num > 9) {
				base_map[i + d_r[pos]][j + d_c[pos]].num = 9;
			}

			if (temp[i][j].color != 'W') {
				base_map[i + d_r[pos]][j + d_c[pos]].color = temp[i][j].color;
			}
		}
	}
}

void rotate_map(int index, int rot) {
	if (rot == 1) {
		int row, col;
		for (int k = 0; k < 2; k++) {
			row = k;
			col = 3 - k;
			for (int i = k; i < 4 - k; i++) {
				temp[i][col] = added_map[index][row][i];
			}

			row = 3 - k;
			col = 3 - k;
			for (int i = k; i < 4 - k; i++) {
				temp[row][3 - i] = added_map[index][i][col];
			}

			row = 3 - k;
			col = k;
			for (int i = k; i < 4 - k; i++) {
				temp[i][col] = added_map[index][row][i];
			}

			row = k;
			col = k;
			for (int i = k; i < 4 - k; i++) {
				temp[row][3 - i] = added_map[index][i][col];
			}
		}
	}
	else if (rot == 2) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				temp[i][j] = added_map[index][3 - i][3 - j];
			}
		}
	}
	else if (rot == 3) {
		int row, col;
		for (int k = 0; k < 2; k++) {
			row = k;
			col = 3 - k;
			for (int i = k; i < 4 - k; i++) {
				temp[row][i] = added_map[index][i][col];
			}

			row = 3 - k;
			col = 3 - k;
			for (int i = k; i < 4 - k; i++) {
				temp[i][col] = added_map[index][row][3 - i];
			}

			row = 3 - k;
			col = k;
			for (int i = k; i < 4 - k; i++) {
				temp[row][i] = added_map[index][i][col];
			}

			row = k;
			col = k;
			for (int i = k; i < 4 - k; i++) {
				temp[i][col] = added_map[index][row][3 - i];
			}
		}
	}
	else {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				temp[i][j] = added_map[index][i][j];
			}
		}
	}
}

int find_cnt() {
	int R = 0, B = 0, G = 0, Y = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (base_map[i][j].color == 'R') {
				R += base_map[i][j].num;
			}
			else if (base_map[i][j].color == 'B') {
				B += base_map[i][j].num;
			}
			else if (base_map[i][j].color == 'G') {
				G += base_map[i][j].num;
			}
			else if (base_map[i][j].color == 'Y') {
				Y += base_map[i][j].num;
			}
		}
	}
	int cnt = 7 * R + 5 * B + 3 * G + 2 * Y;
	return cnt;
}

void calc_map() {
	init();
	for (int i = 0; i < 3; i++) {
		rotate_map(numbers[i], numbers_2[i]);
		add_map(numbers[i], numbers_3[i]);
	}
	int cnt = find_cnt();
	if (ans < cnt) {
		ans = cnt;
	}
}

void solve_3() {
	if (used_numbers_3 == 3) {
		calc_map();

		return;
	}
	for (int i = 0; i < 4; i++) {
		numbers_3[used_numbers_3] = i;
		used_numbers_3++;
		solve_3();
		used_numbers_3--;
	}
}


void solve_2() {
	if (used_numbers_2 == 3) {
		solve_3();

		return;
	}
	for (int i = 0; i < 4; i++) {
		numbers_2[used_numbers_2] = i;
		used_numbers_2++;
		solve_2();
		used_numbers_2--;
	}
}


void solve() {
	if (used_numbers == 3) {
		solve_2();

		return;
	}
	for (int i = 0; i < n; i++) {
		if (is_used[i] == 0) {
			numbers[used_numbers] = i;
			is_used[i] = 1;
			used_numbers++;
			solve();
			is_used[i] = 0;
			used_numbers--;
		}
	}
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int t = 0; t < n; t++) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> added_map[t][i][j].num;
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> added_map[t][i][j].color;
			}
		}
	}

	
	solve();
	cout << ans;

	return 0;
}