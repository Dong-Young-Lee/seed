#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 300;

int w, h, r;
int map[MAX][MAX];
int num;

void print_map() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}

void rotate() {
	int row, col;

	for (int t = 0; t < num; t++) {
		int left_up = map[t][t];

		// up
		row = t;
		col = w - 1 - t;
		for (int c = t; c < col; c++) {
			map[row][c] = map[row][c + 1];
		}

		// right
		row = h - 1 - t;
		col = w - 1 - t;
		for (int r = t; r < row; r++) {
			map[r][col] = map[r + 1][col];
		}

		// down
		row = h - 1 - t;
		col = w - 1 - t;
		for (int c = col; c > t; c--) {
			map[row][c] = map[row][c - 1];
		}

		// left
		row = h - 1 - t;
		col = t;
		for (int r = row; r > 1 + t; r--) {
			map[r][col] = map[r - 1][col];
		}

		map[t + 1][t] = left_up;
	}
}

int main(void) {
	cin >> h >> w >> r;
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> map[i][j];
		}
	}
	
	num = min(w, h) / 2;

	for (int i = 0; i < r; i++) {
		rotate();
	}
	print_map();
	
	return 0;
}