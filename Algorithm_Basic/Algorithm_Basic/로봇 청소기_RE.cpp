#include <iostream>
using namespace std;

const int MAX = 50;

typedef struct {
	int row;
	int col;
	int dir;
}info;

int n, m;
int map[MAX][MAX];
info robot;

int d_r[4] = { -1, 0, 1, 0 };
int d_c[4] = { 0, 1, 0, -1 };

int ans;

int main(void) {
	cin >> n >> m;
	cin >> robot.row >> robot.col >> robot.dir;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	int one_flag = 1;
	int not_go = 0;
	while (true) {
		if (not_go == 4) {
			int back_dir = (robot.dir + 2) % 4;
			int back_row = robot.row + d_r[back_dir];
			int back_col = robot.col + d_c[back_dir];
			if (back_row >= 0 && back_row < n && back_col >= 0 && back_col < m) {
				if (map[back_row][back_col] != 1) {
					robot.row = back_row;
					robot.col = back_col;
					one_flag = 0;
					not_go = 0;
					continue;
				}
				else {
					break;
				}
			}
			else {
				break;
			}
		}
		if (one_flag) {
			map[robot.row][robot.col] = 2;
			ans++;
		}
		int next_dir = (robot.dir + 3) % 4;
		int next_row = robot.row + d_r[next_dir];
		int next_col = robot.col + d_c[next_dir];
		if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < m) {
			if (map[next_row][next_col] == 0) {
				robot.row = next_row;
				robot.col = next_col;
				robot.dir = next_dir;
				one_flag = 1;
				not_go = 0;
				continue;
			}
			else {
				robot.dir = next_dir;
				one_flag = 0;
				not_go++;
				continue;
			}
		}
		else {
			robot.dir = next_dir;
			one_flag = 0;
			not_go++;
			continue;
		}
	}
	cout << ans;

	return 0;
}