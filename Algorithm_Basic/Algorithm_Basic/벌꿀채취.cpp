#include <iostream>
#include <string.h>
using namespace std;

const int MAX = 10;

int tc, t, n, m, c;
int map[MAX][MAX];

int visited[MAX][MAX];
int numbers[2][2];
int used_numbers;

int visited_2[5];
int numbers_2[5];
int used_numbers_2;

int ans;

int val[2];

void solve2(int who, int select) {
	if (used_numbers_2 == select) {
		int sum = 0;
		for (int i = 0; i < select; i++) {
			sum += map[numbers[who][0]][numbers[who][1] + numbers_2[i]];
		}
		if (sum <= c) {

			int cal_sum = 0;
			for (int i = 0; i < select; i++) {
				cal_sum += map[numbers[who][0]][numbers[who][1] +
					numbers_2[i]] * map[numbers[who][0]][numbers[who][1] + numbers_2[i]];
			}
			if (val[who] < cal_sum) {
				val[who] = cal_sum;
			}

		}
		return;
	}

	for (int i = 0; i < m; i++) {
		if (used_numbers_2 > 0) {
			if (i > numbers_2[used_numbers_2 - 1]) {
				if (visited_2[i] == 0) {
					visited_2[i] = 1;
					numbers_2[used_numbers_2] = i;
					used_numbers_2++;
					solve2(who, select);
					visited_2[i] = 0;
					used_numbers_2--;
				}
			}
		}
		else {
			if (visited_2[i] == 0) {
				visited_2[i] = 1;
				numbers_2[used_numbers_2] = i;
				used_numbers_2++;
				solve2(who, select);
				visited_2[i] = 0;
				used_numbers_2--;
			}
		}

	}
}

void solve() {
	if (used_numbers == 2) {
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= m; j++) {
				val[0] = 0;
				val[1] = 0;
				solve2(0, i);
				solve2(1, j);

				int res = val[0] + val[1];
				if (ans < res) {
					ans = res;
				}
			}
		}
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (used_numbers >= 0) {
				if (i == numbers[used_numbers - 1][0]) {
					if (j >= numbers[used_numbers - 1][1]) {
						if (j + m <= n) {
							int is_able = 1;
							for (int k = 0; k < m; k++) {
								if (visited[i][j + k] == 1) {
									is_able = 0;
									break;
								}
							}
							if (is_able) {
								for (int k = 0; k < m; k++) {
									visited[i][j + k] = 1;
								}
								numbers[used_numbers][0] = i;
								numbers[used_numbers][1] = j;
								used_numbers++;
								solve();
								for (int k = 0; k < m; k++) {
									visited[i][j + k] = 0;
								}
								used_numbers--;
							}
						}
					}
				}
				else if (i > numbers[used_numbers - 1][0]) {
					if (j + m <= n) {
						int is_able = 1;
						for (int k = 0; k < m; k++) {
							if (visited[i][j + k] == 1) {
								is_able = 0;
								break;
							}
						}
						if (is_able) {
							for (int k = 0; k < m; k++) {
								visited[i][j + k] = 1;
							}
							numbers[used_numbers][0] = i;
							numbers[used_numbers][1] = j;
							used_numbers++;
							solve();
							for (int k = 0; k < m; k++) {
								visited[i][j + k] = 0;
							}
							used_numbers--;
						}
					}
				}
			}
			else {
				if (j + m <= n) {
					int is_able = 1;
					for (int k = 0; k < m; k++) {
						if (visited[i][j + k] == 1) {
							is_able = 0;
							break;
						}
					}
					if (is_able) {
						for (int k = 0; k < m; k++) {
							visited[i][j + k] = 1;
						}
						numbers[used_numbers][0] = i;
						numbers[used_numbers][1] = j;
						used_numbers++;
						solve();
						for (int k = 0; k < m; k++) {
							visited[i][j + k] = 0;
						}
						used_numbers--;
					}
				}
			}
		}
	}
}

int main(void) {
	cin >> tc;
	for (t = 1; t <= tc; t++) {
		ans = 0;

		cin >> n >> m >> c;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}

		solve();

		cout << "#" << t << " " << ans << '\n';

	}

	return 0;
}