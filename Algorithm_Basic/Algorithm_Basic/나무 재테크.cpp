#include <iostream>
#include <queue>
using namespace std;

typedef struct {
	int tree_number;
	int ground;
	priority_queue<int, vector<int>, greater<int> > age;
}tree;

int n, m, k;
int plus_ground[10][10];

tree info[10][10];

// 12시 부터 시계방향
int d_r[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int d_c[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

void spring_summer() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int number = info[i][j].tree_number;
			if (number > 0) {
				queue<int> live;
				queue<int> dead;
				for (int q = 0; q < number; q++) {
					int cur_age = info[i][j].age.top();
					int cur_ground = info[i][j].ground;
					info[i][j].age.pop();
					if (cur_age > cur_ground) {
						dead.push(cur_age / 2);
						info[i][j].tree_number--;
					}
					else {
						info[i][j].ground -= cur_age;
						live.push(cur_age + 1);
					}
				}

				while (!live.empty()) {
					info[i][j].age.push(live.front());
					live.pop();
				}

				while (!dead.empty()) {
					info[i][j].ground += dead.front();
					dead.pop();
				}
			}
		}
	}
}

void fall_winter() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int number = info[i][j].tree_number;
			if (number > 0) {
				queue<int> temp;
				for (int q = 0; q < number; q++) {
					temp.push(info[i][j].age.top());
					int cur_age = info[i][j].age.top();
					info[i][j].age.pop();
					if (cur_age % 5 == 0) {
						for (int it = 0; it < 8; it++) {
							int next_row = i + d_r[it];
							int next_col = j + d_c[it];
							if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < n) {
								info[next_row][next_col].tree_number++;
								info[next_row][next_col].age.push(1);
							}
						}
					}
				}
				while (!temp.empty()) {
					info[i][j].age.push(temp.front());
					temp.pop();
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			info[i][j].ground += plus_ground[i][j];
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> plus_ground[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			info[i][j].ground = 5;
		}
	}

	for (int i = 0; i < m; i++) {
		int r, c, a;
		cin >> r >> c >> a;
		info[r - 1][c - 1].tree_number++;
		info[r - 1][c - 1].age.push(a);
	}

	while (k--) {
		spring_summer();
		fall_winter();
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans += info[i][j].tree_number;
		}
	}

	cout << ans;

	return 0;
}