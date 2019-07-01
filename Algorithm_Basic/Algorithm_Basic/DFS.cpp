#include <iostream>
#include <vector>
using namespace std;

void dfs(vector< vector<int> > &adj_list, vector<bool> &visited, int vertex) {
	visited[vertex] = true;
	cout << vertex << ' ';

	int adj_number = adj_list[vertex].size();
	for (int i = 0; i < adj_number; i++) {
		int adj_vertex = adj_list[vertex][i];
		if (!visited[adj_vertex]) {
			dfs(adj_list, visited, adj_vertex);
		}
	}
}

int main(void) {
	int n, m, start;
	cin >> n >> m >> start;
	
	vector< vector<int> > adj_list(n + 1, vector<int>());
	vector<bool> visited(n + 1, false);

	for (int i = 0; i < m; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		adj_list[v1].push_back(v2);
		adj_list[v2].push_back(v1);
	}

	dfs(adj_list, visited, start);


	return 0;
}