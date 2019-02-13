// 다른 방법 존재
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
int r, c;
vector<string> graph(50);
vector< vector<int> > movement(50, vector<int>(50, -1));
queue< pair<int, int> > q;

int d_row[4] = {-1, 0, 1, 0};
int d_col[4] = {0, 1, 0, -1};

int s_r, s_c;
int d_r = -1;
int d_c = -1;

void bfs() {
	q.push(make_pair(s_r, s_c));
	movement[s_r][s_c] = 0;

	while (!q.empty()) {
		int cur_row = q.front().first;
		int cur_col = q.front().second;
		char cur_kinds = graph[cur_row][cur_col];
		q.pop();

		for (int i = 0; i < 4; i++) {
			int adj_row = cur_row + d_row[i];
			int adj_col = cur_col + d_col[i];
			if (adj_row >= 0 && adj_row <= r - 1 &&
				adj_col >= 0 && adj_col <= c - 1) {
				char adj_kinds = graph[adj_row][adj_col];
				if (cur_kinds == '*') {
					if (adj_kinds == '.') {
						graph[adj_row][adj_col] = '*';
						q.push(make_pair(adj_row,adj_col));
					}
				}
				if (cur_kinds == 'S') {
					if (adj_kinds == '.' && movement[adj_row][adj_col] == -1) {
						graph[adj_row][adj_col] = 'S';
						q.push(make_pair(adj_row, adj_col));
						movement[adj_row][adj_col] = movement[cur_row][cur_col] + 1;
					}
					if (adj_kinds == 'D') {
						movement[adj_row][adj_col] = movement[cur_row][cur_col] + 1;
						d_r = adj_row;
						d_c = adj_col;
						return;
					}
				}
			}
		}

	}
}

int main(void) {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> graph[i];
		for (int j = 0; j < c; j++) {
			if (graph[i][j] == 'S') {
				s_r = i;
				s_c = j;
			}
			if (graph[i][j] == '*') {
				q.push(make_pair(i, j));
			}
		}
	}

	bfs();

	if (d_r != -1 && d_c != -1) {
		cout << movement[d_r][d_c];
	}
	else {
		cout << "KAKTUS";
	}

	return 0;
}
