#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

const int MAX_ROW = 12;
const int MAX_COL = 6;

vector< vector<char> > map(MAX_ROW, vector<char>(MAX_COL));
vector< vector<bool> > visited(MAX_ROW, vector<bool>(MAX_COL, false));
vector< vector<bool> > copy_visited(MAX_ROW, vector<bool>(MAX_COL, false));
queue< pair<int, int> > q;

int d_r[4] = { -1, 0, 1, 0 };
int d_c[4] = { 0, 1, 0, -1 };
int cnt;

int bfs(int row, int col) {
	stack< pair<int, int> > s;
	q.push(make_pair(row, col));
	visited[row][col] = true;
	char first = map[row][col];
	s.push(make_pair(row, col));

	while (!q.empty()) {
		int cur_row = q.front().first;
		int cur_col = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_row = cur_row + d_r[i];
			int next_col = cur_col + d_c[i];
			if (next_row >= 0 && next_row < MAX_ROW && next_col >= 0 && next_col < MAX_COL) {
				if (!visited[next_row][next_col] && map[next_row][next_col] != '.' && map[next_row][next_col] == first) {
					visited[next_row][next_col] = true;
					s.push(make_pair(next_row, next_col));
					q.push(make_pair(next_row, next_col));
					cnt++;
				}
			}
		}
	}

	if (cnt >= 4) {
		while (!s.empty()) {
			int temp_row = s.top().first;
			int temp_col = s.top().second;
			map[temp_row][temp_col] = '.';
			s.pop();
		}
	}

	return cnt;
}

bool boom() {
	visited = copy_visited;
	bool boom = false;
	for (int i = 0; i < MAX_ROW; i++) {
		for (int j = 0; j < MAX_COL; j++) {
			if (!visited[i][j] && map[i][j] != '.') {
				cnt = 1;
				cnt = bfs(i, j);
				if (cnt >= 4) {
					boom = true;
				}
			}
		}
	}
	return boom;
}

void puyo_down() {
	for (int j = 0; j < MAX_COL; j++) {
		for (int i = MAX_ROW - 2; i >= 0; i--) {
			if (map[i][j] != '.') {
				int empty_cnt = 0;
				for (int k = 1; k < MAX_ROW - i; k++) {
					if (map[i + k][j] != '.') {
						break;
					}
					else {
						empty_cnt++;
					}
				}
				if (empty_cnt > 0) {
					map[i + empty_cnt][j] = map[i][j];
					map[i][j] = '.';
				}
			}
		}
	}
}

int main(void) {
	for (int i = 0; i < MAX_ROW; i++) {
		for (int j = 0; j < MAX_COL; j++) {
			cin >> map[i][j];
		}
	}

	int ans = 0;

	while(boom()){
		ans++;
		puyo_down();
	}

	cout << ans;

	return 0;
}