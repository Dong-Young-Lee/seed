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
int processor_cnt;
info processors[MAX];

int numbers[MAX];
int used_numbers;

int d_r[4] = { -1, 0, 1, 0 };
int d_c[4] = { 0, 1, 0, -1 };

int cnt;
int ans;

int is_valid(int dir, int index) {
	if (dir == 0) {
		int ok = 1;
		int dist = processors[index].row;
		for (int r = 1; r <= dist; r++) {
			if (map[dist - r][processors[index].col] != 0) {
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
		int ok = 1;
		int dist = n - processors[index].col - 1;
		for (int c = 1; c <= dist; c++) {
			if (map[processors[index].row][processors[index].col + c] != 0) {
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
		int ok = 1;
		int dist = n - processors[index].row - 1;
		for (int r = 1; r <= dist; r++) {
			if (map[processors[index].row + r][processors[index].col] != 0) {
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
	else if (dir == 3) {
		int ok = 1;
		int dist = processors[index].col;
		for (int c = 1; c <= dist; c++) {
			if (map[processors[index].row][dist - c] != 0) {
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
}

void revise(int type, int dir, int index) {
	if (type) {
		if (dir == 0) {
			int dist = processors[index].row;
			for (int r = 1; r <= dist; r++) {
				map[dist - r][processors[index].col] = 2;
				cnt++;
			}
		}
		else if (dir == 1) {
			int dist = n - processors[index].col - 1;
			for (int c = 1; c <= dist; c++) {
				map[processors[index].row][processors[index].col + c] = 2;
				cnt++;
			}
		}
		else if (dir == 2) {
			int dist = n - processors[index].row - 1;
			for (int r = 1; r <= dist; r++) {
				map[processors[index].row + r][processors[index].col] = 2;
				cnt++;
			}
		}
		else if (dir == 3) {
			int dist = processors[index].col;
			for (int c = 1; c <= dist; c++) {
				map[processors[index].row][dist - c] = 2;
				cnt++;
			}
		}
	}
	else {
		if (dir == 0) {
			int dist = processors[index].row;
			for (int r = 1; r <= dist; r++) {
				map[dist - r][processors[index].col] = 0;
				cnt--;
			}
		}
		else if (dir == 1) {
			int dist = n - processors[index].col - 1;
			for (int c = 1; c <= dist; c++) {
				map[processors[index].row][processors[index].col + c] = 0;
				cnt--;
			}
		}
		else if (dir == 2) {
			int dist = n - processors[index].row - 1;
			for (int r = 1; r <= dist; r++) {
				map[processors[index].row + r][processors[index].col] = 0;
				cnt--;
			}
		}
		else if (dir == 3) {
			int dist = processors[index].col;
			for (int c = 1; c <= dist; c++) {
				map[processors[index].row][dist - c] = 0;
				cnt--;
			}
		}
	}
}

void perm_repet() {
	if (used_numbers == processor_cnt) {
		if (ans > cnt) {
			ans = cnt;
		}

		return;
	}

	for (int i = 0; i < 4; i++) {
		if (is_valid(i, used_numbers)) {
			revise(1, i, used_numbers);
			numbers[used_numbers++] = i;
			perm_repet();
			used_numbers--;
			revise(0, i, used_numbers);
		}
	}
}

void remove_processor() {
	for (int i = 0; i < processor_cnt; i++) {
		int impossible = 1;
		for (int j = 0; j < 4; j++) {
			if (is_valid(j, i)) {
				impossible = 0;
				break;
			}
		}
		if (impossible) {
			processors[i] = processors[processor_cnt - 1];
			i--;
			processor_cnt--;
		}
	}
}

int main(void) {
	cin >> T;
	for (test_case = 1; test_case <= T; test_case++) {
		processor_cnt = 0;
		ans = 2147483647;

		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				if (map[i][j] == 1) {
					if (i != 0 && i != n - 1 && j != 0 && j != n - 1) {
						processors[processor_cnt++] = { i, j };
					}
				}
			}
		}

		remove_processor();
		
		perm_repet();

		cout << "#" << test_case << " " << ans << "\n";

	}
	return 0;
}