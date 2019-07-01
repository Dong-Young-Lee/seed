#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

const int MAX = 1000;

vector< vector<int> > map(MAX, vector<int>(MAX));
vector< vector< vector<bool> > > visited(MAX, vector< vector<bool> >(MAX, vector<bool>(2)));
queue< tuple<int, int, bool> > q;

int d_r[4] = { -1, 0, 1, 0 };
int d_c[4] = { 0, 1, 0, -1 };

int n, m;

int cnt;
bool reach = false;
int bfs() {
	visited[0][0][0] = true;
	q.push(make_tuple(0, 0, false));
	cnt = 1;
	
	while(!q.empty()) {

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
							if (!cur_crashed) {
								visited[next_row][next_col][1] = true;
								q.push(make_tuple(next_row, next_col, true));
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
			break;
		}
		cnt++;
	}
	if (!visited[n - 1][m - 1][0] && !visited[n - 1][m - 1][1]) {
		return -1;
	}
	else {
		return cnt;
	}
}

int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	printf("%d\n", bfs());

	return 0;
}
