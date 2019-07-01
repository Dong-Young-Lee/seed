#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int map[8][8];

int zero_cnt;
int one_cnt;
int two_cnt;

vector< pair<int, int> > zero_vec;
vector<int> wall_vec;
vector< pair<int, int> > two_vec;

int d_r[4] = { -1, 1, 0, 0 };
int d_c[4] = { 0, 0, -1, 1 };

int ans;

void bfs() {
	int cnt = 0;
	int visited[8][8] = { 0, };
	queue< pair<int, int> > q;
	for (int i = 0; i < two_cnt; i++) {
		q.push(make_pair(two_vec[i].first, two_vec[i].second));
		visited[two_vec[i].first][two_vec[i].second] = 1;
		cnt++;
	}

	while (!q.empty()) {
		int cur_row = q.front().first;
		int cur_col = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int next_row = cur_row + d_r[i];
			int next_col = cur_col + d_c[i];
			if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < m) {
				int next_type = map[next_row][next_col];
				if (next_type == 0 && !visited[next_row][next_col]) {
					visited[next_row][next_col] = 1;
					q.push(make_pair(next_row, next_col));
					cnt++;
				}
			}
		}
	}

	int empty = m * n - one_cnt - 3 - cnt;
	if (empty > ans) {
		ans = empty;
	}
}

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int input;
			cin >> input;
			map[i][j] = input;
			if (input == 0) {
				zero_cnt++;
				zero_vec.push_back(make_pair(i, j));
			}
			else if (input == 1) {
				one_cnt++;
			}
			else {
				two_cnt++;
				two_vec.push_back(make_pair(i, j));
			}
		}
	}
	for (int i = 0; i < zero_cnt - 3; i++) {
		wall_vec.push_back(0);
	}
	wall_vec.push_back(1);
	wall_vec.push_back(1);
	wall_vec.push_back(1);

	int wall_cnt = 0;
	do {
		for (int i = 0; i < zero_cnt; i++) {
			if (wall_vec[i]) {
				map[zero_vec[i].first][zero_vec[i].second] = 1;
				wall_cnt++;
				if (wall_cnt == 3) {
					break;
				}
			}
		}

		bfs();

		for (int i = 0; i < zero_cnt; i++) {
			if (wall_vec[i]) {
				map[zero_vec[i].first][zero_vec[i].second] = 0;
				wall_cnt--;
				if (wall_cnt == 0) {
					break;
				}
			}
		}
	} while (next_permutation(wall_vec.begin(), wall_vec.end()));
	
	cout << ans;
	
	return 0;
}