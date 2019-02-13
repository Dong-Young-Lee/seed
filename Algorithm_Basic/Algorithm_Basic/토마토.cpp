#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector< vector<int> > graph(1001, vector<int>(1001));
vector< vector<bool> > visited(1001, vector<bool>(1001, false));
vector< vector<int> > movement(1001, vector<int>(1001, -1));

queue< pair<int, int> > q;

int d_row[4] = {-1, 0, 1, 0};
int d_col[4] = {0, 1, 0, -1};

void bfs(int row, int col) {
	while (!q.empty()) {
		int cur_row = q.front().first;
		int cur_col = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int adj_row = cur_row + d_row[i];
			int adj_col = cur_col + d_col[i];
			if (adj_row >= 1 && adj_row <= row &&
				adj_col >= 1 && adj_col <= col) {
				if (graph[adj_row][adj_col] >= 0 && visited[adj_row][adj_col] == false) {
					q.push(make_pair(adj_row, adj_col));
					visited[adj_row][adj_col] = true;
					graph[adj_row][adj_col] = graph[cur_row][cur_col] + 1;
				}
			}
		}
	}
}

int main(void) {
	int m, n;
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 1) {
				// 시작 위치가 여러 곳이면 q에 start를 다 넣어줌
				q.push(make_pair(i, j));
				visited[i][j] = true;
			}
		}
	}
	
	int zero_flag = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (graph[i][j] == 0) {
				zero_flag = 1;
			}
		}
	}
	if (zero_flag == 0) {
		cout << 0;
		return 0;
	}

	bfs(n, m);
	
	int result = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (graph[i][j] == 0) {
				cout << -1;
				return 0;
			}
			if (result < graph[i][j]) {
				result = graph[i][j];
			}
		}
	}
	
	cout << result - 1;

	return 0;
}