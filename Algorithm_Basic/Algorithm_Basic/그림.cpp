#include <iostream>
#include <queue>
using namespace std;

int n, m;

int arr[500][500];
bool visited[500][500];
queue< pair<int, int> > q;

int paint_number;
int max_paint;

int d_r[4] = {-1, 0, 1, 0};
int d_c[4] = {0, 1, 0, -1};

void bfs(int row, int col) {
	int cnt = 0;
	q.push(make_pair(row, col));
	visited[row][col] = true;

	while (!q.empty()) {
		int cur_row = q.front().first;
		int cur_col = q.front().second;
		q.pop();
		cnt++;
		for (int i = 0; i < 4; i++) {
			int adj_row = cur_row + d_r[i];
			int adj_col = cur_col +d_c[i];
			if (adj_row >= 0 && adj_row < n && adj_col >= 0 && adj_col < m) {
				if (!visited[adj_row][adj_col] && arr[adj_row][adj_col] == 1) {
					q.push(make_pair(adj_row, adj_col));
					visited[adj_row][adj_col] = true;
				}
			}
		}
	}

	if (max_paint < cnt) {
		max_paint = cnt;
	}
}

void all_bfs() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && arr[i][j] == 1) {
				paint_number++;
				bfs(i, j);
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	all_bfs();

	cout << paint_number << '\n' << max_paint;

	return 0;
}