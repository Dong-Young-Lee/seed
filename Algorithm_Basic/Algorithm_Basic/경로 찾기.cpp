#include <iostream>
#include <string.h>
using namespace std;

int n;
int graph[100][100];
int visited[100];

void dfs(int vertex) {
	for (int i = 0; i < n; i++) {
		if (!visited[i] && graph[vertex][i]) {
			visited[i] = 1;
			dfs(i);
		}
	}
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}
	
	for (int i = 0; i < n; i++) {
		memset(visited, 0, sizeof(visited));
		dfs(i);
		for (int j = 0; j < n; j++) {
			cout << visited[j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}