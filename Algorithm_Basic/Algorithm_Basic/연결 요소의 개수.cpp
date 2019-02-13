#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool bfs(int start);

vector< vector<int> > adjacency_list(1001, vector<int>());
vector<bool> visited(1001, false);

bool all_visited(int n) {
	for (int i = 1; i <= n; i++) {
		if (visited[i] == false) {
			return false;
		}
	}
	return true;
}

int connected_component(int n) {
	int count = 0;
	/*
	int start = 1;
	while (!all_visited(n)) {
		if (bfs(start++)) {
			count++;
		}
	}
	*/
	for (int i = 1; i <= n; i++) {
		if (bfs(i)) {
			count++;
		}
	}
	return count;
}

bool bfs(int start) {
	if (visited[start] == true) {
		return false;
	}
	queue<int> q;
	visited[start] = true;
	q.push(start);
	while (!q.empty()) {
		int now_node = q.front();
		q.pop();
		// cout << now_node << ' ';
		int degree = adjacency_list[now_node].size();
		for (int i = 0; i < degree; i++) {
			int next_node = adjacency_list[now_node][i];
			if (visited[next_node] == false) {
				visited[next_node] = true;
				q.push(next_node);
			}
		}
	}
	return true;
}

int main(void) {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adjacency_list[a].push_back(b);
		adjacency_list[b].push_back(a);
	}

	cout << connected_component(n);
	

	return 0;
}