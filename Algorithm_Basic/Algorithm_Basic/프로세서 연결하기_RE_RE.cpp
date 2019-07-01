#include <iostream>
using namespace std;

typedef struct {
	int row;
	int col;
}info;

const int MAX = 12;
int map[MAX][MAX];
int test_case, T;
int n;

info processor[MAX];
int processor_cnt;

int used_numbers;

int not_cunnected;
int max_cunnected;
int cnt;
int ans;

void modify_map(int dir, int draw) {
	info cur = processor[used_numbers];
	if (draw == 1) {
		if (dir == 0) {
			int dist_max = cur.row;
			for (int dist = 1; dist <= dist_max; dist++) {
				map[cur.row - dist][cur.col] = 2;
			}
			cnt += dist_max;
		}
		else if (dir == 1) {
			int dist_max = n - cur.col - 1;
			for (int dist = 1; dist <= dist_max; dist++) {
				map[cur.row][cur.col + dist] = 2;
			}
			cnt += dist_max;
		}
		else if (dir == 2) {
			int dist_max = n - cur.row - 1;
			for (int dist = 1; dist <= dist_max; dist++) {
				map[cur.row + dist][cur.col] = 2;
			}
			cnt += dist_max;
		}
		else if (dir == 3) {
			int dist_max = cur.col;
			int ok = 1;
			for (int dist = 1; dist <= dist_max; dist++) {
				map[cur.row][cur.col - dist] = 2;
			}
			cnt += dist_max;
		}
	}
	else {
		if (dir == 0) {
			int dist_max = cur.row;
			for (int dist = 1; dist <= dist_max; dist++) {
				map[cur.row - dist][cur.col] = 0;
			}
			cnt -= dist_max;
		}
		else if (dir == 1) {
			int dist_max = n - cur.col - 1;
			for (int dist = 1; dist <= dist_max; dist++) {
				map[cur.row][cur.col + dist] = 0;
			}
			cnt -= dist_max;
		}
		else if (dir == 2) {
			int dist_max = n - cur.row - 1;
			for (int dist = 1; dist <= dist_max; dist++) {
				map[cur.row + dist][cur.col] = 0;
			}
			cnt -= dist_max;
		}
		else if (dir == 3) {
			int dist_max = cur.col;
			int ok = 1;
			for (int dist = 1; dist <= dist_max; dist++) {
				map[cur.row][cur.col - dist] = 0;
			}
			cnt -= dist_max;
		}
	}
}

int is_valid(int dir) {
	info cur = processor[used_numbers];
	if (dir == 0) {
		int dist_max = cur.row;
		int ok = 1;
		for (int dist = 1; dist <= dist_max; dist++) {
			if (map[cur.row - dist][cur.col] != 0) {
				ok = 0;
				break;
			}
		}
		if (ok == 1) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (dir == 1) {
		int dist_max = n - cur.col - 1;
		int ok = 1;
		for (int dist = 1; dist <= dist_max; dist++) {
			if (map[cur.row][cur.col + dist] != 0) {
				ok = 0;
				break;
			}
		}
		if (ok == 1) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (dir == 2) {
		int dist_max = n - cur.row - 1;
		int ok = 1;
		for (int dist = 1; dist <= dist_max; dist++) {
			if (map[cur.row + dist][cur.col] != 0) {
				ok = 0;
				break;
			}
		}
		if (ok == 1) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (dir == 3) {
		int dist_max = cur.col;
		int ok = 1;
		for (int dist = 1; dist <= dist_max; dist++) {
			if (map[cur.row][cur.col - dist] != 0) {
				ok = 0;
				break;
			}
		}
		if (ok == 1) {
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
		int cur_cunnected = processor_cnt - not_cunnected;

		if (max_cunnected < cur_cunnected) {
			max_cunnected = cur_cunnected;
			ans = cnt;
		}

		if (max_cunnected == cur_cunnected) {
			if (ans > cnt) {
				ans = cnt;
			}
		}

		return;
	}

	for (int i = 0; i < 5; i++) {
		if (is_valid(i)) {
			modify_map(i, 1);
			if (i == 4) {
				not_cunnected++;
			}
			used_numbers++;
			repet_perm();
			used_numbers--;
			if (i == 4) {
				not_cunnected--;
			}
			modify_map(i, 0);
		}
	}
}

int main(void) {
	cin >> T;
	for (test_case = 1; test_case <= T; test_case++) {
		ans = 2147483647;
		processor_cnt = 0;
		max_cunnected = 0;

		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				if (map[i][j] == 1) {
					if (i >= 1 && i < n - 1 && j >= 1 && j < n - 1) {
						processor[processor_cnt] = { i,j };
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