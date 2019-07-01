#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector< vector<int> > castle(50, vector<int>(50));
vector< vector<bool> > visited(50, vector<bool>(50, false));
queue< pair<int, int> > q;

vector<int> room_size_vec;

// ³²8 µ¿4 ºÏ2 ¼­1
int d_r[9] = {0, 0, -1, 0, 0, 0, 0, 0, 1};
int d_c[9] = {0, -1, 0, 0, 1, 0, 0, 0, 0};

int max_room = 1;
int number_of_rooms = 0;
int next_max_room = 1;

int bfs(int row, int col) {
	int max = 1;
	q.push(make_pair(row, col));
	visited[row][col] = true;

	while (!q.empty()) {
		int cur_row = q.front().first;
		int cur_col = q.front().second;
		q.pop();
		int cur_info = 15 - castle[cur_row][cur_col];
		castle[cur_row][cur_col] = number_of_rooms;
		
		queue<int> path;
		int divisor = 8;
		while (cur_info != 0) {
			if (cur_info / divisor == 1) {
				path.push(divisor);
			}
			cur_info %= divisor;
			divisor /= 2;
		}

		while (!path.empty()) {
			int next_direction = path.front();
			path.pop();

			int next_row = cur_row + d_r[next_direction];
			int next_col = cur_col + d_c[next_direction];
			if (!visited[next_row][next_col]) {
				q.push(make_pair(next_row, next_col));
				visited[next_row][next_col] = true;
				max++;
			}
		}
	}
	return max;
}

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> castle[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				int room_size = bfs(i, j);
				room_size_vec.push_back(room_size);
				number_of_rooms++;
				if (max_room < room_size) {
					max_room = room_size;
				}
			}
		}
	}
	cout << number_of_rooms << '\n';
	cout << max_room << '\n';

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 4; k++) {
				int next_row = i + d_r[1 << k];
				int next_col = j + d_c[1 << k];
				if (next_row >= 0 && next_row < m && next_col >= 0 && next_col < n) {
					if (castle[i][j] != castle[next_row][next_col]) {
						int temp_size = room_size_vec[castle[i][j]] + room_size_vec[castle[next_row][next_col]];
						if (next_max_room < temp_size) {
							next_max_room = temp_size;
						}
					}
				}
			}
		}
	}

	cout << next_max_room;

	return 0;
}