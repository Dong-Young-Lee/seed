#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

vector< vector<int> > graph(26, vector<int>(26));
vector< vector<bool> > visited(26, vector<bool>(26, false));
int d_row[4] = {-1, 0, 1, 0};
int d_column[4] = {0, 1, 0, -1};

int bfs(int v, int row, int column) {
	queue< pair<int, int> > q;
	q.push(make_pair(row, column));
	visited[row][column] = true;
	int count = 1;
	while (!q.empty()) {
		int current_row = q.front().first;
		int current_column = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int adjacent_row = current_row + d_row[i];
			int adjacent_column = current_column + d_column[i];
			if (adjacent_row >= 1 && adjacent_row <= v
				&& adjacent_column >= 1 && adjacent_column <= v) {
				if (graph[adjacent_row][adjacent_column]  == 1 && 
					visited[adjacent_row][adjacent_column] == false) {
					q.push(make_pair(adjacent_row, adjacent_column));
					visited[adjacent_row][adjacent_column] = true;
					count++;
				}
			}
		}
	}
	return count;
}

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}

	vector<int> count;
	int num = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (graph[i][j] == 1 && visited[i][j] == false) {
				count.push_back(bfs(n, i, j));
				num += 1;
			}
		}
	}

	sort(count.begin(), count.end());
	
	int count_size = count.size();
	printf("%d\n", num-1);
	for (int i = 0; i < count_size; i++) {
		printf("%d\n", count[i]);
	}

	return 0;
}