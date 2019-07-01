#include <iostream>
using namespace std;

typedef struct {
	int row;
	int col;
}pos;

const int MAX = 100;
int map[MAX][MAX];

int tc = 10;

pos cur;

int ans;

int move() {
	while (cur.row != 0) {
		int cur_col_left = cur.col - 1;
		int cur_col_right = cur.col + 1;

		if (cur_col_left >= 0) {
			if (map[cur.row][cur_col_left]) {
				while (map[cur.row][cur_col_left]) {
					cur_col_left--;
					
					if (cur_col_left == -1) {
						break;
					}
					
				}
				cur.row--;
				cur.col = cur_col_left + 1;
				continue;
			}
		}

		if (cur_col_right < MAX) {
			if (map[cur.row][cur_col_right]) {
				while (map[cur.row][cur_col_right]) {
					cur_col_right++;
					
					if (cur_col_right == MAX) {
						break;
					}
				}
				cur.row--;
				cur.col = cur_col_right - 1;
				continue;
			}
		}

		cur.row--;
	}
	return cur.col;
}

int main(void) {
	for (int t = 1; t <= tc; t++) {
		int a;
		cin >> a;
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				cin >> map[i][j];
				if (map[i][j] == 2) {
					cur.row = i;
					cur.col = j;
				}
			}
		}

		ans = move();

		cout << '#' << t << ' ' << ans << '\n';

	}
	return 0;
}