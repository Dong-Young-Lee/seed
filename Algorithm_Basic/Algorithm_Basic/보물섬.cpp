#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
using namespace std;

const int MAX = 50;

int n, m;
char map[MAX][MAX];
int visited[MAX][MAX];
queue< pair<int, int> > q;

int d_r[4] = { -1, 0, 1, 0 };
int d_c[4] = { 0, 1, 0, -1 };

int flag;

int ans;

void bfs(int row, int col) {
	int time = -1;

	q.push({ row, col });
	visited[row][col] = flag;

	while (!q.empty()) {
		int q_size = q.size();
		for (int i = 0; i < q_size; i++) {
			int cur_row = q.front().first;
			int cur_col = q.front().second;
			q.pop();

			for (int j = 0; j < 4; j++) {
				int next_row = cur_row + d_r[j];
				int next_col = cur_col + d_c[j];
				if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < m) {
					if (map[next_row][next_col] == 'L' && visited[next_row][next_col] != flag) {
						visited[next_row][next_col] = flag;
						q.push({ next_row, next_col });
					}
				}
			}
		}
		time++;
	}

	if (ans <= time) {
		ans = time;
	}
}

void solve() {
	flag = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'L') {
				bfs(i, j);
				flag++;
			}
		}
	}
}

int main(void) {
	scanf("%d %d\n", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%c\n", &map[i][j]);
		}
	}

	solve();
	printf("%d", ans);

	return 0;
}