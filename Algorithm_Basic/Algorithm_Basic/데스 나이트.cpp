#include <iostream>
#include <queue>
using namespace std;

const int MAX = 200;

int visited[MAX][MAX];

int d_r[6] = { -2, - 2, 0, 0, 2, 2 };
int d_c[6] = { -1, 1, -2, 2, -1, 1 };

int n, sr, sc, dr, dc;

queue< pair<int, int> > q;

int ans = -1;

void bfs() {
	q.push({ sr, sc });
	visited[sr][sc] = 1;

	while (!q.empty()) {
		int cur_row = q.front().first;
		int cur_col = q.front().second;
		q.pop();

		if (cur_row == dr && cur_col == dc) {
			ans = visited[dr][dc] - 1;
			return;
		}
		for (int i = 0; i < 6; i++) {
			int next_row = cur_row + d_r[i];
			int next_col = cur_col + d_c[i];
			if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < n) {
				if (visited[next_row][next_col] == 0) {
					visited[next_row][next_col] = visited[cur_row][cur_col] + 1;
					q.push({ next_row, next_col });
				}
			}
		}
	}
}

int main(void) {
	cin >> n >> sr >> sc >> dr >> dc;

	bfs();
	cout << ans;
	return 0;
}