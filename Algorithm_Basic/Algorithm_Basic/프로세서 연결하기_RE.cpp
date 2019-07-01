#include <iostream>
using namespace std;

typedef struct {
	int row;
	int col;
}info;

const int MAX = 12;
int test_case, T;
int n;

int map[MAX][MAX];

info processors[MAX];
int processor_cnt;

int d_r[4] = { -1, 0, 1, 0 };
int d_c[4] = { 0, 1, 0, -1 };

int numbers[MAX];
int used_numbers;

int cnt;
int ans;

int max_processor;

void print_map() {
	cout << "< MAP >\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void modify_map(int dir, int draw) {
	int row = processors[used_numbers].row;
	int col = processors[used_numbers].col;

	if (draw == 1) {
		if (dir == 3) {
			int dist = col;
			for (int i = 1; i <= dist; i++) {
				map[row][col - i] = 2;
			}
			cnt += dist;
		}
		else if (dir == 2) {
			int dist = n - row - 1;
			for (int i = 1; i <= dist; i++) {
				map[row + i][col] = 2;
			}
			cnt += dist;
		}
		else if (dir == 1) {
			int dist = n - col - 1;
			for (int i = 1; i <= dist; i++) {
				map[row][col + i] = 2;
			}
			cnt += dist;
		}
		else if (dir == 0) {
			int dist = row;
			for (int i = 1; i <= dist; i++) {
				map[row - i][col] = 2;
			}
			cnt += dist;
		}
	}
	else {
		if (dir == 3) {
			int dist = col;
			for (int i = 1; i <= dist; i++) {
				map[row][col - i] = 0;
			}
			cnt -= dist;
		}
		else if (dir == 2) {
			int dist = n - row - 1;
			for (int i = 1; i <= dist; i++) {
				map[row + i][col] = 0;
			}
			cnt -= dist;
		}
		else if (dir == 1) {
			int dist = n - col - 1;
			for (int i = 1; i <= dist; i++) {
				map[row][col + i] = 0;
			}
			cnt -= dist;
		}
		else if (dir == 0) {
			int dist = row;
			for (int i = 1; i <= dist; i++) {
				map[row - i][col] = 0;
			}
			cnt -= dist;
		}
	}
}

int is_valid(int dir) {
	int row = processors[used_numbers].row;
	int col = processors[used_numbers].col;

	if (dir == 3) {
		int dist = col;
		int ok = 1;
		for (int i = 1; i <= dist; i++) {
			if (map[row][col - i] != 0) {
				ok = 0;
				break;
			}
		}
		if (ok) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (dir == 2) {
		int dist = n - row - 1;
		int ok = 1;
		for (int i = 1; i <= dist; i++) {
			if (map[row + i][col] != 0) {
				ok = 0;
				break;
			}
		}
		if (ok) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (dir == 1) {
		int dist = n - col - 1;
		int ok = 1;
		for (int i = 1; i <= dist; i++) {
			if (map[row][col + i] != 0) {
				ok = 0;
				break;
			}
		}
		if (ok) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (dir == 0) {
		int dist = row;
		int ok = 1;
		for (int i = 1; i <= dist; i++) {
			if (map[row - i][col] != 0) {
				ok = 0;
				break;
			}
		}
		if (ok) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		return 1;
	}
}

void repet_perm() {
	if (used_numbers == processor_cnt) {

		int cur_processors = processor_cnt;
		for (int i = 0; i < used_numbers; i++) {
			if (numbers[i] == 4) {
				cur_processors--;
			}
		}

		if (max_processor < cur_processors) {
			max_processor = cur_processors;
			ans = cnt;
		}

		if (cur_processors == max_processor) {
			if (ans > cnt) {
				ans = cnt;
			}
		}

		return;
	}

	for (int i = 0; i < 5; i++) {
		if (is_valid(i)) {
			modify_map(i, 1);
			numbers[used_numbers] = i;
			used_numbers++;
			repet_perm();
			used_numbers--;
			modify_map(i, 0);
		}
	}
}

int main(void) {
	cin >> T;
	for (test_case = 1; test_case <= T; test_case++) {
		processor_cnt = 0;
		max_processor = 0;
		ans = 2147483647;

		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				if (map[i][j] == 1) {
					if (i >= 1 && i < n - 1 && j >= 1 && j < n - 1) {
						processors[processor_cnt] = { i, j };
						processor_cnt++;
					}
				}
			}
		}

		repet_perm();

		cout << "#" << test_case << " " << ans << "\n";

	}
	return 0;
}