#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

const int goal = 4;

int cube[5][5][5];
int maze[5][5][5];
int maze_init[5][5][5];
int visited[5][5][5];
int temp[5][5][1];

int nums[5];
int isused[5];
int used_nums;

int numbers[5];
int used_numbers;

int ans = 100000;

// 북 동 남 서 위 아래
int d_r[6] = { -1, 0, 1, 0, 0, 0 };
int d_c[6] = { 0, 1, 0, -1, 0, 0 };
int d_l[6] = { 0, 0, 0, 0, -1, 1 };

typedef struct coordinate {
	int row;
	int col;
	int lay;
}coordinate;

void print_maze() {
	cout << "< print maze >" << '\n';
	for (int k = 0; k < 5; k++) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				cout << maze[i][j][k] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}
}

void print_cube() {
	cout << "< print cube >" << '\n';
	for (int k = 0; k < 5; k++) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				cout << cube[i][j][k] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}
}

void print_visited() {
	cout << "< print visited >" << '\n';
	for (int k = 0; k < 5; k++) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				cout << visited[i][j][k] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}
}

void copy_maze(int layer) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			maze[i][j][layer] = temp[i][j][0];
		}
	}
}

void rotate_90(int num) {
	int row, col;
	for (int k = 0; k < 2; k++) {
		// right
		row = k;
		col = 4 - k;
		for (int i = k; i < 5 - k; i++) {
			temp[i][col][0] = maze[row][i][num];
		}

		// down
		row = 4 - k;
		col = 4 - k;
		for (int i = k; i < 5 - k; i++) {
			temp[row][4 - i][0] = maze[i][col][num];
		}

		// left
		row = 4 - k;
		col = k;
		for (int i = k; i < 5 - k; i++) {
			temp[i][col][0] = maze[row][i][num];
		}

		// up
		row = k;
		col = k;
		for (int i = k; i < 5 - k; i++) {
			temp[row][i][0] = maze[4 - i][col][num];
		}
	}
	temp[2][2][0] = maze[2][2][num];
	copy_maze(num);
}

void rotate(int num, int dir) {
	// 0 : 0

	// 1 : 90
	if (dir == 1) {
		rotate_90(num);
	}
	// 2 : 180
	else if (dir == 2) {
		rotate_90(num);
		rotate_90(num);
	}
	// 3 : 270
	else if (dir == 3) {
		rotate_90(num);
		rotate_90(num);
		rotate_90(num);
	}
}

void init() {
	for (int k = 0; k < 5; k++) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				maze[i][j][k] = maze_init[i][j][k];
			}
		}
	}
}

int bfs() {
	int arrive = 0;
	int cnt = 0;
	visited[0][0][0] = 1;
	queue< coordinate > q;
	q.push({ 0, 0, 0 });

	while (!q.empty()) {
		int q_size = q.size();
		for (int i = 0; i < q_size; i++) {
			int cur_row = q.front().row;
			int cur_col = q.front().col;
			int cur_lay = q.front().lay;
			q.pop();

			if (cur_row == goal && cur_col == goal && cur_lay == goal) {
				arrive = 1;
				break;
			}

			for (int j = 0; j < 6; j++) {
				int next_row = cur_row + d_r[j];
				int next_col = cur_col + d_c[j];
				int next_lay = cur_lay + d_l[j];
				if (next_row >= 0 && next_row < 5 &&
					next_col >= 0 && next_col < 5 &&
					next_lay >= 0 && next_lay < 5) {
					if (!visited[next_row][next_col][next_lay]) {
						if (cube[next_row][next_col][next_lay] == 1) {
							visited[next_row][next_col][next_lay] = 1;
							q.push({ next_row, next_col, next_lay });
						}
					}
				}
			}
		}
		if (arrive) {
			return cnt;
		}
		cnt++;
	}

	return -1;
}


void go(int cube_layer, int layer) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cube[i][j][cube_layer] = maze[i][j][layer];
		}
	}
}

void solve2() {
	if (used_nums == 5) {
		memset(visited, 0, sizeof(visited));

		for (int i = 0; i < 5; i++) {
			go(i, nums[i]);
		}

		if (cube[0][0][0] == 1) {
			int ret = bfs();

			if (ret > 0) {
				if (ans > ret) {
					ans = ret;
				}
			}
		}

		return;
	}
	for (int i = 0; i < 5; i++) {
		if (!isused[i]) {
			isused[i] = 1;
			nums[used_nums] = i;
			used_nums++;
			solve2();
			isused[i] = 0;
			used_nums--;
		}
	}
}

void solve() {
	if (used_numbers == 5) {
		init();

		for (int i = 0; i < 5; i++) {
			rotate(i, numbers[i]);
		}

		solve2();

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
	for (int k = 0; k < 5; k++) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				cin >> maze_init[i][j][k];
			}
		}
	}

	solve();

	if (ans == 100000) {
		cout << -1;
	}
	else {
		cout << ans;
	}
	return 0;
}