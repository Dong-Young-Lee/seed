// 브루트 포스 - 시간초과
/*
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int n, m;
	cin >> n >> m;
	vector< vector<int> > friends(m, vector<int>(2));
	for (int i = 0; i < m; i++) {
		cin >> friends[i][0] >> friends[i][1];
	}
	
	vector< vector<int> > graph(n, vector<int>(n, 0));
	for (int i = 0; i < m; i++) {
		graph[friends[i][0]][friends[i][1]] = 1;
		graph[friends[i][1]][friends[i][0]] = 1;
		
	}

	
	int ans = 0;
	int flag = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (graph[i][j] == 1) {
				for (int a = 0; a < n; a++) {
					if (a == i) continue;
					if (graph[j][a] == 1) {
						for (int b = 0; b < n; b++) {
							if (b == i || b == j) continue;
							if (graph[a][b] == 1) {
								for (int c = 0; c < n; c++) {
									if (c == i || c == j || c == a) continue;
									if (graph[b][c] == 1) {
										ans = 1;
										flag = 1;
									}
									if (flag == 1) break;
								}
							}
							if (flag == 1) break;
						}

					}
					if (flag == 1) break;
				}
			}
			if (flag == 1) break;
		}
		if (flag == 1) break;
	}

	cout << ans;
	
	return 0;
}
*/