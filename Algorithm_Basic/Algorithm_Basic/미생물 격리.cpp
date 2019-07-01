#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

typedef struct {
	int row;
	int col;
	int num;
	int dir;
}microbe;

// ╩С го аб ©Л
int d_r[4] = { -1, 1, 0, 0 };
int d_c[4] = { 0, 0, -1, 1 };

int main(void) {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		int n, m, k;
		cin >> n >> m >> k;
		queue<microbe> q;
		for (int i = 0; i < k; i++) {
			int r, c, m_n, d;
			cin >> r >> c >> m_n >> d;
			q.push({ r, c, m_n, d - 1 });
		}
		
		for (int i = 0; i < m; i++) {
			int overlap_check[100][100];
			memset(overlap_check, 0, sizeof(overlap_check));
			int q_size = q.size();
			for(int j=0; j<q_size; j++) {
				int cur_row = q.front().row;
				int cur_col = q.front().col;
				int cur_num = q.front().num;
				int cur_dir = q.front().dir;
				q.pop();

				int next_row = cur_row + d_r[cur_dir];
				int next_col = cur_col + d_c[cur_dir];
				int next_num;
				int next_dir;
				if (next_row == 0 || next_row == n - 1 || next_col == 0 || next_col == n - 1) {
					next_num = cur_num / 2;
					if (next_num == 0) continue;
					if (cur_dir == 0) {
						next_dir = 1;
					}
					else if (cur_dir == 1) {
						next_dir = 0;
					}
					else if (cur_dir == 2) {
						next_dir = 3;
					}
					else {
						next_dir = 2;
					}
				}
				else {
					next_num = cur_num;
					next_dir = cur_dir;
				}

				overlap_check[next_row][next_col]++;
				q.push({ next_row, next_col, next_num, next_dir });
			}

			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					if (overlap_check[j][k] > 1) {
						vector<microbe> over_v;
						int m_num = overlap_check[j][k];
						int find_num = 0;
						int temp_row;
						int temp_col;
						while (find_num != m_num) {
							temp_row = q.front().row;
							temp_col = q.front().col;
							if (temp_row == j && temp_col == k) {
								find_num++;
								over_v.push_back(q.front());
								q.pop();
							}
							else {
								q.push(q.front());
								q.pop();
							}
						}
						
						int mn_max_num;
						int mn_max = 0;
						int v_size = over_v.size();
						int sum_num = 0;
						for (int w = 0; w < v_size; w++) {
							sum_num += over_v[w].num;
							if (mn_max < over_v[w].num) {
								mn_max_num = w;
								mn_max = over_v[w].num;
							}
						}
						int sum_dir = over_v[mn_max_num].dir;

						q.push({ temp_row, temp_col, sum_num, sum_dir });
					}
				}
			}
		}

		int ans = 0;
		while (!q.empty()) {
			ans += q.front().num;
			q.pop();
		}

		cout << '#' << t << ' ' << ans << '\n';
	}
	return 0;
}