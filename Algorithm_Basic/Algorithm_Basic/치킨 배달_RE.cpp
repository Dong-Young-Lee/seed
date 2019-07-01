#include <iostream>
using namespace std;

typedef struct {
	int row;
	int col;
	int dist;
}house;

typedef struct {
	int row;
	int col;
}chicken;

int n, m;

house house_arr[100];
int house_num;
chicken chicken_arr[13];
int chicken_num;

int is_used[13];
int numbers[13];
int used_numbers;

int ans = 2147483647;

void dist_init() {
	for (int i = 0; i < house_num; i++) {
		house_arr[i].dist = 250;
	}
}

void find_dist() {
	dist_init();

	for (int i = 0; i < house_num; i++) {
		for (int j = 0; j < used_numbers; j++) {
			int row_dist = house_arr[i].row - chicken_arr[numbers[j]].row;
			if (row_dist < 0) row_dist = -row_dist;
			int col_dist = house_arr[i].col - chicken_arr[numbers[j]].col;
			if (col_dist < 0) col_dist = -col_dist;

			int cur_dist = row_dist + col_dist;

			if (house_arr[i].dist > cur_dist) {
				house_arr[i].dist = cur_dist;
			}
		}
	}

	int total_dist = 0;
	for (int i = 0; i < house_num; i++) {
		total_dist += house_arr[i].dist;
	}

	if (ans > total_dist) {
		ans = total_dist;
	}
}

void solve(int max_num) {
	if (used_numbers == max_num) {
		find_dist();
	}

	for (int i = 0; i < chicken_num; i++) {
		if (used_numbers > 0) {
			if (i > numbers[used_numbers - 1]) {
				if (is_used[i] == 0) {
					is_used[i] = 1;
					numbers[used_numbers] = i;
					used_numbers++;
					solve(max_num);
					is_used[i] = 0;
					used_numbers--;
				}
			}
		}
		else {
			if (is_used[i] == 0) {
				is_used[i] = 1;
				numbers[used_numbers] = i;
				used_numbers++;
				solve(max_num);
				is_used[i] = 0;
				used_numbers--;
			}
		}
	}
}

int main(void) {
	cin >> n >> m;
	int input;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> input;
			if (input == 1) {
				house_arr[house_num].row = i;
				house_arr[house_num].col = j;
				house_num++;
			}
			else if (input == 2) {
				chicken_arr[chicken_num].row = i;
				chicken_arr[chicken_num].col = j;
				chicken_num++;
			}
		}
	}

	solve(m);

	cout << ans;

	return 0;
}