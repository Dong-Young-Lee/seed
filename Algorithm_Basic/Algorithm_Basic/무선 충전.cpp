#include <iostream>
using namespace std;

typedef struct {
	int row;
	int col;
	int c;
	int p;
}bc_info;

typedef struct {
	int row;
	int col;
}p_info;

const int MAP_MAX = 10;
const int M_MAX = 100;
const int BC_MAX = 8;


int T, t, m, a;
int move_arr[2][M_MAX];
int map[MAP_MAX][MAP_MAX];
bc_info bc[BC_MAX + 1];


int d_r[5] = { 0, -1, 0, 1, 0 };
int d_c[5] = { 0, 0, 1, 0, -1 };

p_info people[2];

int numbers[2];
int used_numbers;

int max_sum;
int ans;

void find_max_charge() {
	int sum = 0;
	if (numbers[0] == numbers[1]) {
		sum = bc[numbers[0]].p;
	}
	else {
		for (int i = 0; i < 2; i++) {
			sum += bc[numbers[i]].p;
		}
	}

	if (max_sum < sum) {
		max_sum = sum;
	}
}

int valid_bc(int p, int bc_num) {
	int row_dist = bc[bc_num].row - people[p].row;
	if (row_dist < 0) row_dist = -row_dist;
	int col_dist = bc[bc_num].col - people[p].col;
	if (col_dist < 0) col_dist = -col_dist;
	int dist = row_dist + col_dist;

	if (dist <= bc[bc_num].c) {
		return 1;
	}
	else return 0;
}

void repet_comb() {
	if (used_numbers == 2) {
		/*
		for (int i = 0; i < 2; i++) {
			cout << numbers[i] << ' ';
		}
		cout << '\n';
		*/
		find_max_charge();

		return;
	}

	for (int i = 0; i < a + 1; i++) {
		if (used_numbers == 0) {
			if (valid_bc(0, i)) {
				numbers[used_numbers] = i;
				used_numbers++;
				repet_comb();
				used_numbers--;
			}
		}
		else {
			if (valid_bc(1, i)) {
				numbers[used_numbers] = i;
				used_numbers++;
				repet_comb();
				used_numbers--;
			}
		}
	}
}

int main(void) {
	cin >> T;
	for (t = 1; t <= T; t++) {
		cin >> m >> a;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < m; j++) {
				cin >> move_arr[i][j];
			}
		}

		bc[0] = {0, 0, 100, 0};

		for (int i = 1; i < a + 1; i++) {
			int row, col, c, p;
			cin >> col >> row >> c >> p;
			bc[i] = { row - 1, col - 1, c, p };
		}

		// init
		int time = 0;
		people[0].row = 0;
		people[0].col = 0;
		people[1].row = MAP_MAX - 1;
		people[1].col = MAP_MAX - 1;
		ans = 0;

		while (time < m + 1) {
			/*
			cout << "time : " << time << '\n';
			cout << "0 : (" << people[0].row << ", " << people[0].col << ")\n";
			cout << "1 : (" << people[1].row << ", " << people[1].col << ")\n";
			*/
			max_sum = 0;
			repet_comb();
			ans += max_sum;

			if (time != m) {
				for (int i = 0; i < 2; i++) {
					people[i].row += d_r[move_arr[i][time]];
					people[i].col += d_c[move_arr[i][time]];
				}
			}

			time++;
		}

		cout << "#" << t << " " << ans << '\n';
	}

	return 0;
}