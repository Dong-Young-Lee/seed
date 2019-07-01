#include <iostream>
#include <vector>
using namespace std;

typedef struct {
	int row;
	int col;
	int num;
}cctv;

int n, m;
int map[8][8];
int map_copy[8][8];
int cctv_cnt;

vector<cctv> cctv_vec;

int numbers[8];
int used_numbers;

int ans = 64;

void init_map() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			map[i][j] = map_copy[i][j];
		}
	}
}

void cctv_up(int row, int col) {
	for (int i = row - 1; i >= 0; i--) {
		if (map[i][col] == 0) {
			map[i][col] = -1;
		}
		else if (map[i][col] == 6) {
			return;
		}
	}
}

void cctv_down(int row, int col) {
	for (int i = row + 1; i < n; i++) {
		if (map[i][col] == 0) {
			map[i][col] = -1;
		}
		else if (map[i][col] == 6) {
			return;
		}
	}
}

void cctv_left(int row, int col) {
	for (int i = col - 1; i >= 0; i--) {
		if (map[row][i] == 0) {
			map[row][i] = -1;
		}
		else if (map[row][i] == 6) {
			return;
		}
	}
}

void cctv_right(int row, int col) {
	for (int i = col + 1; i < m; i++) {
		if (map[row][i] == 0) {
			map[row][i] = -1;
		}
		else if (map[row][i] == 6) {
			return;
		}
	}
}



void cctv_set(int row, int col, int num, int dir) {
	if (num == 1) {
		if (dir == 0) {
			cctv_up(row, col);
		}
		else if (dir == 1) {
			cctv_down(row, col);
		}
		else if (dir == 2) {
			cctv_left(row, col);
		}
		else {
			cctv_right(row, col);
		}
	}
	else if (num == 2) {
		if (dir == 0 || dir == 1) {
			cctv_up(row, col);
			cctv_down(row, col);
		}
		else {
			cctv_left(row, col);
			cctv_right(row, col);
		}
	}
	else if (num == 3) {
		if (dir == 0) {
			cctv_up(row, col);
			cctv_right(row, col);
		}
		else if (dir == 1) {
			cctv_down(row, col);
			cctv_left(row, col);
		}
		else if (dir == 2) {
			cctv_left(row, col);
			cctv_up(row, col);
		}
		else {
			cctv_right(row, col);
			cctv_down(row, col);
		}
	}
	else if (num == 4) {
		if (dir == 0) {
			cctv_left(row, col);
			cctv_up(row, col);
			cctv_right(row, col);
		}
		else if (dir == 1) {
			cctv_right(row, col);
			cctv_down(row, col);
			cctv_left(row, col);
		}
		else if (dir == 2) {
			cctv_down(row, col);
			cctv_left(row, col);
			cctv_up(row, col);
		}
		else {
			cctv_up(row, col);
			cctv_right(row, col);
			cctv_down(row, col);
		}
	}
	else {
		cctv_up(row, col);
		cctv_down(row, col);
		cctv_left(row, col);
		cctv_right(row, col);
	}
}

void solve2() {
	for (int i = 0; i < cctv_cnt; i++) {
		cctv_set(cctv_vec[i].row, cctv_vec[i].col, cctv_vec[i].num, numbers[i]);
	}
}

int find_blind_spot() {
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				ret++;
			}
		}
	}
	return ret;
}

void solve() {
	if (used_numbers == cctv_cnt) {
		init_map();
		solve2();
		int blind = find_blind_spot();
		if (ans > blind) {
			ans = blind;
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		numbers[used_numbers] = i;
		used_numbers++;
		solve();
		used_numbers--;
	}
}

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map_copy[i][j];
			if (map_copy[i][j] >= 1 && map_copy[i][j] <= 5) {
				cctv_vec.push_back({ i,j,map_copy[i][j] });
				cctv_cnt++;
			}
		}
	}

	solve();
	cout << ans;

	return 0;
}