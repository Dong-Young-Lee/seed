#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int map[20][20];

int zero_cnt;
vector< pair<int, int> > zero_vec;
vector<int> permutation;

int two_cnt;
queue< pair<int, int> > two_queue;

int two_visited[20][20];

int d_r[4] = { -1, 1, 0, 0 };
int d_c[4] = { 0, 0, -1, 1 };

vector<int> group_size;

int ans;

void two_bfs(int row, int col) {
	int cnt = 0;
	queue< pair<int, int> > q;
	q.push(make_pair(row, col));
	two_visited[row][col] = 1;

	while (!q.empty()) {
		int cur_row = q.front().first;
		int cur_col = q.front().second;
		q.pop();
		cnt++;

		for (int i = 0; i < 4; i++) {
			int next_row = cur_row + d_r[i];
			int next_col = cur_col + d_c[i];
			if (next_row == -1 || next_row == n || next_col == -1 || next_col == m) continue;
			int next_type = map[next_row][next_col];
			if (next_type == 2 && !two_visited[next_row][next_col]) {
				two_visited[next_row][next_col] = 1;
				q.push(make_pair(next_row, next_col));
			}
		}
	}
	group_size.push_back(cnt);
}

int bfs(int row, int col, int num) {
	int visited[20][20] = { 0, };
	queue< pair<int, int> > q;
	visited[row][col] = 1;
	q.push(make_pair(row, col));

	while (!q.empty()) {
		int cur_row = q.front().first;
		int cur_col = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int next_row = cur_row + d_r[i];
			int next_col = cur_col + d_c[i];
			if (next_row == -1 || next_row == n || next_col == -1 || next_col == m) continue;
			int next_type = map[next_row][next_col];
			if (next_type == 0) return 0;
			if (next_type == 2 && !visited[next_row][next_col]) {
				visited[next_row][next_col] = 1;
				q.push(make_pair(next_row, next_col));
			}
		}
	}

	return group_size[num];
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
			else if (input == 2) {
				two_cnt++;
				two_queue.push(make_pair(i, j));
			}
		}
	}

	int temp = zero_cnt - 2;
	for (int i = 0; i < temp; i++) {
		permutation.push_back(0);
	}
	permutation.push_back(1);
	permutation.push_back(1);

	for (int i = 0; i < two_cnt; i++) {
		int two_row = two_queue.front().first;
		int two_col = two_queue.front().second;
		if (!two_visited[two_row][two_col]) {
			two_bfs(two_row, two_col);
			two_queue.push(two_queue.front());
			two_queue.pop();
		}
		else {
			two_queue.pop();
		}
	}
	int group_num = group_size.size();

	int one = 0;
	do {
		for (int i = 0; i < zero_cnt; i++) {
			if (permutation[i] == 1) {
				map[zero_vec[i].first][zero_vec[i].second] = 1;
				one++;
				if (one == 2) {
					break;
				}
			}
		}

		int dead = 0;
		for (int i = 0; i < group_num; i++) {
			int two_row = two_queue.front().first;
			int two_col = two_queue.front().second;

			dead += bfs(two_row, two_col, i);

			two_queue.push(two_queue.front());
			two_queue.pop();
		}

		if (ans < dead) {
			ans = dead;
		}

		for (int i = 0; i < zero_cnt; i++) {
			if (permutation[i] == 1) {
				map[zero_vec[i].first][zero_vec[i].second] = 0;
				one--;
				if (one == 0) {
					break;
				}
			}
		}
	} while (next_permutation(permutation.begin(), permutation.end()));

	cout << ans;

	return 0;
}