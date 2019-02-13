#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int d_row[4] = {-1, 0, 1, 0};
int d_column[4] = {0, 1, 0, -1};

void bfs(vector< vector<int> > &graph, vector< vector<bool> > &visited, vector< vector<int> > &movement, int row, int column) {
	queue< pair<int, int> > q;
	q.push(make_pair(1, 1));
	visited[1][1] = true;
	movement[1][1] = 1;

	while (!q.empty()) {
		int current_row = q.front().first;
		int current_column = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int adjacent_row = current_row + d_row[i];
			int adjacent_column = current_column + d_column[i];
			if (adjacent_row >= 1 && adjacent_row <= row &&
				adjacent_column >= 1 && adjacent_column <= column) {
				if (graph[adjacent_row][adjacent_column] == 1 &&
					visited[adjacent_row][adjacent_column] == false) {
					q.push(make_pair(adjacent_row, adjacent_column));
					visited[adjacent_row][adjacent_column] = true;
					// ÇÙ½É
					movement[adjacent_row][adjacent_column] = movement[current_row][current_column] + 1;


				}
			}
		}
	}
}

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);

	vector< vector<int> > graph(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}

	vector< vector<bool> > visited(n + 1, vector<bool>(m + 1, false));
	vector< vector<int> > movement(n + 1, vector<int>(m + 1, 0));
	bfs(graph, visited, movement, n, m);

	printf("%d\n", movement[n][m]);

	return 0;
}