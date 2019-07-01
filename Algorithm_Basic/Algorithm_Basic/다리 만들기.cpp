#include <iostream>
#include <queue>
using namespace std;

typedef struct {
	int row;
	int col;
	int num;
}info;

const int MAX = 100;
int n;
int map[MAX][MAX];
int visited[MAX][MAX];
queue< pair<int, int> > q;
int flag;

int d_r[4] = { -1, 0, 1, 0 };
int d_c[4] = { 0, 1, 0, -1 };

info two[2];

int ans = 2147483647;

void print_visited() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void print_map() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void bfs(int row, int col) {
	visited[row][col] = flag;
	q.push({ row, col });
	
	while (!q.empty()) {
		int cur_row = q.front().first;
		int cur_col = q.front().second;
		q.pop();

		map[cur_row][cur_col] = flag;

		for (int i = 0; i < 4; i++) {
			int next_row = cur_row + d_r[i];
			int next_col = cur_col + d_c[i];
			if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < n) {
				if (map[next_row][next_col] > 0 && visited[next_row][next_col] != flag) {
					visited[next_row][next_col] = flag;
					q.push({ next_row, next_col });
				}
			}
		}
	}
}

void bfs_2(int row, int col) {
	int cnt = 0;
	visited[row][col] = flag;
	q.push({ row, col });

	while (!q.empty()) {
		int cur_row = q.front().first;
		int cur_col = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_row = cur_row + d_r[i];
			int next_col = cur_col + d_c[i];
			if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < n) {
				if (map[next_row][next_col] >= 0 && visited[next_row][next_col] != flag) {
					if (map[next_row][next_col] >= 2) {
						if (cnt == 0) {
							two[cnt++] = { next_row, next_col, map[next_row][next_col] };
						}
						else {
							if (two[0].num != map[next_row][next_col]) {
								two[cnt++] = { next_row, next_col, map[next_row][next_col] };
								while (!q.empty()) {
									q.pop();
								}
								return;
							}

						}
					}
					else {
						visited[next_row][next_col] = flag;
						q.push({ next_row, next_col });
					}
				}
			}
		}
	}
}

void calc_dist() {
	int row_dist = two[0].row - two[1].row;
	if (row_dist < 0) row_dist = -row_dist;
	int col_dist = two[0].col - two[1].col;
	if (col_dist < 0) col_dist = -col_dist;
	int dist = row_dist + col_dist - 1;
	if (ans > dist) {
		ans = dist;
	}
}

void solve() {
	flag = 2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1) {
				bfs(i, j);
				flag++;
			}
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0) {
				// cout << "(" << i << ", " << j << ")\n";
				bfs_2(i, j);
				calc_dist();
				flag++;
			}
		}
	}


}


int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	solve();

	cout << ans;
	return 0;
}