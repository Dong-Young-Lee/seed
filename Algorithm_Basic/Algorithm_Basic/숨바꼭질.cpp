#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph(100001, -1);
vector<bool> visited(100001, false);
queue<int> q;
int n, k;

int d_pos[3] = { -1, 1, 2 };

void bfs() {
	q.push(n);
	visited[n] = true;

	while (!q.empty()) {
		int cur_pos = q.front();
		q.pop();

		for (int i = 0; i < 3; i++) {
			int adj_pos;
			if (i < 2) {
				adj_pos = cur_pos + d_pos[i];
			}
			else {
				adj_pos = cur_pos * d_pos[i];
			}
			if (adj_pos >= 0 && adj_pos <= 100000) {
				if (visited[adj_pos] == false) {
					q.push(adj_pos);
					visited[adj_pos] = true;
					graph[adj_pos] = graph[cur_pos] + 1;
					if (adj_pos == k) {
						return;
					}
				}
			}
		}
	}
}

int main(void) {
	cin >> n >> k;

	graph[n] = 0;
	bfs();

	cout << graph[k];
	return 0;
}