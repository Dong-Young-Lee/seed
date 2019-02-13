#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int d_row[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int d_column[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

void bfs(vector< vector<int> > &graph, vector< vector<bool> > &visited, int row, int column, int w, int h) {
	queue< pair<int, int> > q;
	q.push(make_pair(row, column));
	visited[row][column] = true;
	
	while (!q.empty()) {
		int current_row = q.front().first;
		int current_column = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int adjacent_row = current_row + d_row[i];
			int adjacent_column = current_column + d_column[i];
			if (adjacent_row >= 1 && adjacent_row <= h &&
				adjacent_column >= 1 && adjacent_column <= w) {
				if (visited[adjacent_row][adjacent_column] == false &&
					graph[adjacent_row][adjacent_column] == 1) {
					q.push(make_pair(adjacent_row, adjacent_column));
					visited[adjacent_row][adjacent_column] = true;
				}
			}
		}
	}
}

int main(void) {
	int w, h;
	while (cin >> w >> h) {
		if (w == 0 && h == 0) break;

		vector< vector<int> > graph(h + 1, vector<int>(w + 1));
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				cin >> graph[i][j];
			}
		}
		vector< vector<bool> > visited(h + 1, vector<bool>(w + 1, false));

		int num = 0;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				if (graph[i][j] == 1 && visited[i][j] == false) {
					bfs(graph, visited, i, j, w, h);
					num++;
				}
			}
		}
		cout << num << '\n';
	}

	return 0;
}