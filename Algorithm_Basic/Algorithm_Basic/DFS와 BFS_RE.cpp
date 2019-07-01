#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int n, m, v;
vector< vector<int> > adj_list(1000);

int visited[1000];
void dfs(int vertex) {
	visited[vertex] = 1;
	cout << vertex + 1 << ' ';

	int connected_vertices = adj_list[vertex].size();
	for (int i = 0; i < connected_vertices; i++) {
		int next_vertex = adj_list[vertex][i];
		if (visited[next_vertex]) continue;
		dfs(next_vertex);
	}
}

void bfs(int vertex) {
	queue<int> q;
	visited[vertex] = 1;
	q.push(vertex);

	while (!q.empty()) {
		int cur_vertex = q.front();
		q.pop();
		cout << cur_vertex + 1 << ' ';
		
		int connected_vertices = adj_list[vertex].size();
		for (int i = 0; i < connected_vertices; i++) {
			int next_vertex = adj_list[vertex][i];
			if (visited[next_vertex]) continue;
			visited[next_vertex] = 1;
			q.push(next_vertex);
		}
	}
}

int main(void) {
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		adj_list[v1 - 1].push_back(v2 - 1);
		adj_list[v2 - 1].push_back(v1 - 1);
	}
	
	dfs(v - 1);
	cout << '\n';
	memset(visited, 0, sizeof(visited));
	bfs(v - 1);

	return 0;
}