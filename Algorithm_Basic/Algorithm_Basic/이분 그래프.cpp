// Æ²¸² why?
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool verify_bipartite(vector< vector<int> > &adjacency_list, vector<bool> &colored, int v) {
	for (int i = 1; i <= v; i++) {
		int degree = adjacency_list[i].size();
		for (int j = 0; j < degree; j++) {
			if (colored[i] == colored[adjacency_list[i][j]]) {
				return false;
			}
		}
	}
	return true;
}

void bfs(vector< vector<int> > &adjacency_list, vector<bool> &visited, vector<bool> &colored, int start) {
	queue<int> q;
	q.push(start);
	visited[start] = true;
	colored[start] = true;
	while (!q.empty()) {
		int current_node = q.front();
		q.pop();
		// cout << current_node << ' ';
		int degree = adjacency_list[current_node].size();
		for (int i = 0; i < degree; i++) {
			int adjacent_node = adjacency_list[current_node][i];
			if (visited[adjacent_node] == false) {
				q.push(adjacent_node);
				visited[adjacent_node] = true;
				if (colored[current_node] == true) {
					colored[adjacent_node] = false;
				}
				else {
					colored[adjacent_node] = true;
				}
			}
		}
	}
}

int main(void) {
	int t;
	cin >> t;
	while (t--) {
		int v, e;
		cin >> v >> e;
		// adjacency list
		vector< vector<int> > adjacency_list(v + 1, vector<int>());
		
		for (int i = 1; i <= e; i++) {
			int from, to;
			cin >> from >> to;
			adjacency_list[from].push_back(to);
			adjacency_list[to].push_back(from);
		}

		vector<bool> visited(v + 1, false);
		vector<bool> colored(v + 1);

		bfs(adjacency_list, visited, colored, 1);
		if (verify_bipartite(adjacency_list, colored, v)) {
			cout << "YES";
		}
		else {
			cout << "NO";
		}
		cout << '\n';
	}


	return 0;
}