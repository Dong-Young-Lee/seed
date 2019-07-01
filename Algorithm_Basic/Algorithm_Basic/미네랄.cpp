#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <string.h>
using namespace std;

const int MAX = 100;

char cave[MAX][MAX];
int r, c;
int n;
int stick_height;
int dir = 1;

bool visited[MAX][MAX];
vector< pair<int, int> > cluster;
int d_r[4] = { -1, 0, 1, 0 };
int d_c[4] = { 0, 1, 0, -1 };
vector< pair<int, int> > bottom;

void print_arr() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			printf("%c", cave[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void dfs(int row, int col) {
	visited[row][col] = true;
	cluster.push_back(make_pair(row, col));

	for (int i = 0; i < 4; i++) {
		int adj_row = row + d_r[i];
		int adj_col = col + d_c[i];
		if (adj_row >= 0 && adj_row < r && adj_col >= 0 && adj_col < c) {
			if (!visited[adj_row][adj_col] && cave[adj_row][adj_col] == 'x') {
				dfs(adj_row, adj_col);
			}
		}
	}
}

void down() {
	bottom.push_back(cluster[0]);
	int cluster_size = cluster.size();
	for (int i = 1; i < cluster_size; i++) {
		int bottom_size = bottom.size();
		int other = 1;
		for (int j = 0; j < bottom_size; j++) {
			if (cluster[i].second == bottom[j].second) {
				other = 0;
				if (cluster[i].first > bottom[j].first) {
					bottom[j] = cluster[i];
				}
			}
		}
		if (other) {
			bottom.push_back(cluster[i]);
		}
	}

	int bottom_size = bottom.size();
	vector<int> move;
	for (int i = 0; i < bottom_size; i++) {
		int cur_row = bottom[i].first;
		int cur_col = bottom[i].second;
		int empty = 0;
		for (int j = 1; j < r - bottom[i].first; j++) {
			if (cave[cur_row + j][cur_col] == 'x') {
				break;
			}
			empty++;
		}
		move.push_back(empty);
	}

	int movement = r;
	for (int i = 0; i < bottom_size; i++) {
		if (movement > move[i]) {
			movement = move[i];
		}
	}

	for (int i = 0; i < cluster_size; i++) {
		int cur_row = cluster[i].first;
		int cur_col = cluster[i].second;
		cave[cur_row][cur_col] = '.';
	}

	for (int i = 0; i < cluster_size; i++) {
		int next_row = cluster[i].first + movement;
		int next_col = cluster[i].second;
		cave[next_row][next_col] = 'x';
	}
}

// not used
void find_cluster() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			memset(visited, false, sizeof(visited));
			cluster.clear();
			bottom.clear();
			if (cave[i][j] == 'x') {
				dfs(i, j);
				down();
			}
		}
	}
}

void solve() {
	int row = r - stick_height;
	if (dir == 1) { // คั>
		int col = -1;
		for (int i = 0; i < c; i++) {
			if (cave[row][i] == 'x') {
				cave[row][i] = '.';
				col = i;
				break;
			}
		}
		if (col == -1) return;
		// up
		if (row - 1 >= 0) {
			if (cave[row - 1][col] == 'x') {
				memset(visited, false, sizeof(visited));
				cluster.clear();
				bottom.clear();

				dfs(row - 1, col);
				down();
			}
		}

		// down
		if (row + 1 < r) {
			if (cave[row + 1][col] == 'x') {
				memset(visited, false, sizeof(visited));
				cluster.clear();
				bottom.clear();

				dfs(row + 1, col);
				down();
			}
		}

		// right
		if (col + 1 < c) {
			if (cave[row][col + 1] == 'x') {
				memset(visited, false, sizeof(visited));
				cluster.clear();
				bottom.clear();

				dfs(row, col + 1);
				down();
			}
		}
	}
	else { // <คั
		int col = -1;
		for (int i = c - 1; i >= 0; i--) {
			if (cave[row][i] == 'x') {
				cave[row][i] = '.';
				col = i;
				break;
			}
		}
		if (col == -1) return;
		// up
		if (row - 1 >= 0) {
			if (cave[row - 1][col] == 'x') {
				memset(visited, false, sizeof(visited));
				cluster.clear();
				bottom.clear();

				dfs(row - 1, col);
				down();
			}
		}

		// down
		if (row + 1 < r) {
			if (cave[row + 1][col] == 'x') {
				memset(visited, false, sizeof(visited));
				cluster.clear();
				bottom.clear();

				dfs(row + 1, col);
				down();
			}
		}

		// left
		if (col - 1 >= 0) {
			if (cave[row][col - 1] == 'x') {
				memset(visited, false, sizeof(visited));
				cluster.clear();
				bottom.clear();

				dfs(row, col - 1);
				down();
			}
		}
	}
}

int main(void) {
	scanf("%d %d", &r, &c);
	getchar();
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf("%c", &cave[i][j]);
		}
		getchar();
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &stick_height);
		solve();
		dir = -dir;
	}
	print_arr();

	return 0;
}