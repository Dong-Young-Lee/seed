#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, w, h;
int map[15][12];
int copy_map[15][12];
int visited[15][12];
queue< pair<int, int> > q;

int ans;

int bfs(int col) {
	int visited[15][12] = { 0 };
	int first_row = -1;
	for (int i = 0; i < h; i++) {
		if (map[i][col] != 0) {
			first_row = i;
			break;
		}
	}
	if (first_row == -1) {
		return -1;
	}

	visited[first_row][col] = 1;
	q.push(make_pair(first_row, col));


	while (!q.empty()) {
		int cur_row = q.front().first;
		int cur_col = q.front().second;
		int cur_num = map[cur_row][cur_col];
		map[cur_row][cur_col] = 0;
		q.pop();

		// up
		for (int i = 1; i < cur_num; i++) {
			int up_row = cur_row - i;
			if (up_row >= 0) {
				if (visited[up_row][cur_col]) continue;
				visited[up_row][cur_col] = 1;
				q.push(make_pair(up_row, cur_col));
			}
		}

		// right
		for (int i = 1; i < cur_num; i++) {
			int right_col = cur_col + i;
			if (right_col < w) {
				if (visited[cur_row][right_col]) continue;
				visited[cur_row][right_col] = 1;
				q.push(make_pair(cur_row, right_col));
			}
		}

		// down
		for (int i = 1; i < cur_num; i++) {
			int down_row = cur_row + i;
			if (down_row < h) {
				if (visited[down_row][cur_col]) continue;
				visited[down_row][cur_col] = 1;
				q.push(make_pair(down_row, cur_col));
			}
		}

		// left
		for (int i = 1; i < cur_num; i++) {
			int left_col = cur_col - i;
			if (left_col >= 0) {
				if (visited[cur_row][left_col]) continue;
				visited[cur_row][left_col] = 1;
				q.push(make_pair(cur_row, left_col));
			}
		}

	}
	return 1;
}

void map_down() {
	for (int i = 0; i < w; i++) {
		for (int j = h - 2; j >= 0; j--) {
			if (map[j][i] != 0) {
				int empty = 0;
				for (int k = 1; k < h - j; k++) {
					if (map[j + k][i] != 0) {
						break;
					}
					else {
						empty++;
					}
				}
				if (empty > 0) {
					map[j + empty][i] = map[j][i];
					map[j][i] = 0;
				}
			}
		}
	}
}

void func(vector<int> &numbers, int used_numbers) {
	if (ans == 0) return;
	if (used_numbers == n) {
		
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				map[i][j] = copy_map[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			q = queue< pair<int, int> >();
			if (bfs(numbers[i]) == 1) {
				map_down();
			}
		}

		int cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] != 0) {
					cnt++;
				}
			}
		}
		if (ans > cnt) {
			ans = cnt;
		}

		return;
	}

	for (int i = 0; i < w; i++) {
		numbers.push_back(i);
		used_numbers++;
		func(numbers, used_numbers);
		numbers.pop_back();
		used_numbers--;
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n >> w >> h;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> copy_map[i][j];
			}
		}

		ans = 181;
		vector<int> numbers;
		int used_numbers = 0;
		func(numbers, used_numbers);

		cout << '#' << t << ' ' << ans << '\n';
	}
	return 0;
}