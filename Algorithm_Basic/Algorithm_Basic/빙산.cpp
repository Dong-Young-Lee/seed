#include <iostream>
#include <queue>
using namespace std;

typedef struct {
	int height;
	int row;
	int col;
}info;

const int MAX = 300;

int n, m;
int map[MAX][MAX];
int visited[MAX][MAX];
queue< pair<int, int> > q;

info ice[MAX * MAX];
int ice_cnt;

int flag = 1;

int d_r[4] = { -1, 0, 1, 0 };
int d_c[4] = { 0, 1, 0, -1 };

int ans;

void print_map() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
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

		for (int i = 0; i < 4; i++) {
			int next_row = cur_row + d_r[i];
			int next_col = cur_col + d_c[i];
			if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < m) {
				if (map[next_row][next_col] > 0 && visited[next_row][next_col] != flag) {
					visited[next_row][next_col] = flag;
					q.push({ next_row, next_col });
				}
			}
		}
	}
}

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] > 0) {
				ice[ice_cnt++] = { map[i][j], i, j };
			}
		}
	}

	int year = 0;
	while (true) {
		int cnt = 0;
		for (int i = 0; i < ice_cnt; i++) {
			if (ice[i].height > 0 && visited[ice[i].row][ice[i].col] != flag) {
				bfs(ice[i].row, ice[i].col);
				cnt++;
			}
		}
		flag++;
		if (cnt == 1) {
			for (int i = 0; i < ice_cnt; i++) {
				if (ice[i].height > 0) {
					int zero_cnt = 0;
					for (int j = 0; j < 4; j++) {
						int adj_row = ice[i].row + d_r[j];
						int adj_col = ice[i].col + d_c[j];
						if (adj_row >= 0 && adj_row < n && adj_col >= 0 && adj_col < m) {
							if (map[adj_row][adj_col] == 0) {
								zero_cnt++;
							}
						}
					}
					ice[i].height -= zero_cnt;
					if (ice[i].height <= 0) {
						ice[i].height = -1;
					}

					map[ice[i].row][ice[i].col] -= zero_cnt;
					if (map[ice[i].row][ice[i].col] <= 0) {
						map[ice[i].row][ice[i].col] = -1;
					}
				}
			}

			for (int i = 0; i < ice_cnt; i++) {
				if (ice[i].height == -1) {
					ice[i].height = 0;
					map[ice[i].row][ice[i].col] = 0;
				}
			}

			year++;
		}
		else if (cnt == 0) {
			ans = 0;
			break;
		}
		else {
			ans = year;
			break;
		}
	}
	
	cout << ans;

	return 0;
}