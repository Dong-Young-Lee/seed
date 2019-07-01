#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <tuple>
using namespace std;

int n, m, k;
const int MAX = 1000;

int map[MAX][MAX];
bool visited[MAX][MAX][11];
queue< tuple<int, int, int> > q;

int d_r[4] = { -1, 0, 1, 0 };
int d_c[4] = { 0, 1, 0, -1 };

bool reach;
int cnt;

int bfs() {
	visited[0][0][0] = true;
	q.push(make_tuple(0, 0, 0));
	cnt = 1;

	while (!q.empty()) {
		int q_size = q.size();
		for (int i = 0; i < q_size; i++) {
			int cur_row = get<0>(q.front());
			int cur_col = get<1>(q.front());
			int cur_crashed = get<2>(q.front());
			q.pop();

			if (cur_row == n - 1 && cur_col == m - 1) {
				reach = true;
				break;
			}

			for (int j = 0; j < 4; j++) {
				int next_row = cur_row + d_r[j];
				int next_col = cur_col + d_c[j];
				if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < m) {
					if (!visited[next_row][next_col][cur_crashed]) {
						if (map[next_row][next_col] == 1) {
							if (cur_crashed < k) {
								visited[next_row][next_col][cur_crashed + 1] = true;
								q.push(make_tuple(next_row, next_col, cur_crashed + 1));
							}
						}
						else {
							visited[next_row][next_col][cur_crashed] = true;
							q.push(make_tuple(next_row, next_col, cur_crashed));
						}
					}
				}
			}
		}

		if (reach) {
			return cnt;
		}
		cnt++;
	}
	return -1;
}

int main(void) {
	scanf("%d %d %d", &n, &m, &k);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	printf("%d\n", bfs());

	return 0;
}