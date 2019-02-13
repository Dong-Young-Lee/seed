#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void dfs(vector< vector<int> > &graph, vector<int> &visit, int n, int v) {
	visit[v] = 1;
	cout << v << ' ';
	int degree = graph[v].size();
	for (int i = 0; i < degree; i++) {
		if (visit[graph[v][i]] != 1) {
			dfs(graph, visit, n, graph[v][i]);
		}
	}
}

void bfs(vector< vector<int> > &graph, vector<int> &visit, int n, int v) {
	queue<int> q;
	visit[v] = 1;
	q.push(v);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		cout << node << ' ';
		int degree = graph[node].size();
		for (int i = 0; i < degree; i++) {
			if (visit[graph[node][i]] != 1) {
				visit[graph[node][i]] = 1;
				q.push(graph[node][i]);
			}
		}
	}
}

int main(void) {
	int n, m, v;
	cin >> n >> m >> v;

	vector< vector<int> > graph(n+1, vector<int>());
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	vector<int> visit(n + 1, 0);

	dfs(graph, visit, n, v);
	cout << '\n';
	int visit_size = visit.size();
	for (int i = 0; i < visit_size; i++) {
		visit[i] = 0;
	}
	bfs(graph, visit, n, v);

	return 0;
}