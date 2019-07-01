#include <iostream>
#include <queue>
using namespace std;

const int MAX = 500;
int n, m;
int map[MAX][MAX];
int visited[MAX][MAX];

int d_r[4] = { -1, 0, 1, 0 };
int d_c[4] = { 0, 1, 0, -1 };

int cnt;
int ans;

queue< pair<int, int> > q;

void bfs(int row, int col) {
	int size = 0;
	q.push(make_pair(row, col));
	visited[row][col] = 1;

	while (!q.empty()) {
		int cur_row = q.front().first;
		int cur_col = q.front().second;
		q.pop();
		size++;

		for (int i = 0; i < 4; i++) {
			int next_row = cur_row + d_r[i];
			int next_col = cur_col + d_c[i];
			
			if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < m) {
				if (!visited[next_row][next_col] && map[next_row][next_col]) {
					visited[next_row][next_col] = 1;
					q.push(make_pair(next_row, next_col));
				}
			}
		}
	}

	if (ans < size) {
		ans = size;
	}
}

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && map[i][j]) {
				cnt++;
				bfs(i, j);
			}
		}
	}
	cout << cnt << '\n' << ans;

	return 0;
}