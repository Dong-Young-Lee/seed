#include <iostream>
#include <queue>
using namespace std;

typedef struct {
	int population;
	int border;
}country;

int n, l, r;
country map[50][50];

// ╩С1 го2 аб4 ©Л8
int d_r[4] = { -1, 1, 0, 0 };                                                                                                                                                                                                                                                                                                                                                                                                                     
int d_c[4] = { 0, 0, -1, 1 };

int end_flag;
int ans;

void open_border() {
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n; col++) {
			for (int i = 0; i < 4; i++) {
				int next_row = row + d_r[i];
				int next_col = col + d_c[i];
				if (next_row == -1 || next_row == n || next_col == -1 || next_col == n) continue;
				int diff = map[row][col].population - map[next_row][next_col].population;
				if (diff < 0) diff = -diff;
				if (diff >= l && diff <= r) {
					if (i == 0) {
						map[row][col].border += 1;
					}
					else if (i == 1) {
						map[row][col].border += 2;
					}
					else if (i == 2) {
						map[row][col].border += 4;
					}
					else {
						map[row][col].border += 8;
					}
				}
			}
		}
	}
}

void movement() {
	end_flag = 1;
	ans++;
	int visited[50][50] = { 0, };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && map[i][j].border != 0) {
				int sum = 0;
				int cnt = 0;
				queue< pair<int, int> > q;
				queue < pair<int, int> > country_list;
				visited[i][j] = 1;
				q.push(make_pair(i, j));

				while (!q.empty()) {
					int cur_row = q.front().first;
					int cur_col = q.front().second;
					country_list.push(q.front());
					sum += map[cur_row][cur_col].population;
					cnt++;
					q.pop();

					int dir_vec[4] = { 0, };
					int divisor = 8;
					int quotient = map[cur_row][cur_col].border;
					int index = 3;
					while (divisor != 0) {
						if (quotient / divisor == 1) {
							dir_vec[index] = 1;
						}
						quotient %= divisor;
						divisor >>= 1;
						index--;
					}

					for (int z = 0; z < 4; z++) {
						if (dir_vec[z]) {
							int next_row = cur_row + d_r[z];
							int next_col = cur_col + d_c[z];
							if (!visited[next_row][next_col]) {
								visited[next_row][next_col] = 1;
								q.push(make_pair(next_row, next_col));
							}
						}
					}
				}

				int pl = sum / cnt;
				while(!country_list.empty()) {
					int row = country_list.front().first;
					int col = country_list.front().second;
					if (map[row][col].population != pl) {
						map[row][col].population = pl;
						end_flag = 0;
					}
					country_list.pop();
				}
			}
		}
	}
}

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j].border = 0;
		}
	}
}

void print_border() {
	cout << "< border >\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j].border << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

void print_population() {
	cout << "< population >\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j].population << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j].population;
		}
	}
	while (true) {
		init();
		open_border();
		// print_border();
		// print_population();
		movement();
		if (end_flag) {
			ans--;
			break;
		}
	}
	cout << ans;

	return 0;
}