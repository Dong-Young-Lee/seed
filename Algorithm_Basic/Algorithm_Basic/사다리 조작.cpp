#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int board[31][19];

int n, m, h;
int width;

int isused[270];
int numbers[3];
int used_numbers;

int d_r[3] = { 1, 0, 0 };
int d_c[3] = { 0, -1, 1 };

int ans;
int find_ans = 0;
void print_board() {
	cout << "< BOARD >\n";
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < width; j++) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

int verify_board(int col) {
	int cur_row = 0;
	int cur_col = col;
	while (true) {
		if (cur_row == h) {
			if (cur_col == col) {
				return 1;
			}
			else {
				return 0;
			}
		}
		int left_col = cur_col - 1;
		int right_col = cur_col + 1;
		if (left_col >= 0 && board[cur_row][left_col]) {
			cur_row += 1;
			cur_col -= 2;
		}
		else if (right_col < width && board[cur_row][right_col]) {
			cur_row += 1;
			cur_col += 2;
		}
		else {
			cur_row += 1;
		}
	}
	
	return 0;
}

void set_edge(int num_max, int num) {
	if (used_numbers == num) {
		/*
		cout << "<< ";
		for (int i = 0; i < num; i++) {
			cout << numbers[i] << ' ';
		}
		cout << " >>\n";
		*/
		vector< pair<int, int> > added_edges;
		for (int i = 0; i < num; i++) {
			int row = numbers[i] % h;
			int col = 2 * (numbers[i] / h) + 1;

			if (board[row][col] == 1) {
				return;
			}

			int left_col = col - 2;
			int right_col = col + 2;
			if (col == 1) {
				if (!board[row][right_col]) {
					added_edges.push_back(make_pair(row, col));
				}
				else {
					return;
				}
			}
			else if (col == width - 2) {
				if (!board[row][left_col]) {
					added_edges.push_back(make_pair(row, col));
				}
				else {
					return;
				}
			}
			else {
				if (!board[row][left_col] && !board[row][right_col]) {
					added_edges.push_back(make_pair(row, col));
				}
				else {
					return;
				}
			}
		}

		for (int i = 0; i < num; i++) {
			for (int j = i + 1; j < num; j++) {
				if (added_edges[i].first == added_edges[j].first) {
					int diff = added_edges[i].second - added_edges[j].second;
					if (diff < 0) diff = -diff;
					if (diff == 2) {
						return;
					}
				}
			}
		}

		for (int i = 0; i < num; i++) {
			board[added_edges[i].first][added_edges[i].second] = 1;
		}

		//print_board();

		int complete = 1;
		for (int i = 0; i < width; i += 2) {
			int ok = verify_board(i);
			if (!ok) {
				complete = 0;
				break;
			}
		}

		for (int i = 0; i < num; i++) {
			board[added_edges[i].first][added_edges[i].second] = 0;
		}

		if (complete) {
			ans = num;
			find_ans = 1;
		}

		return;
	}
	for (int i = 0; i < num_max; i++) {
		if (used_numbers > 0) {
			if (i > numbers[used_numbers - 1]) {
				isused[i] = 1;
				numbers[used_numbers] = i;
				used_numbers++;
				set_edge(num_max, num);
				if (find_ans) break;
				isused[i] = 0;
				used_numbers--;
			}
		}
		else {
			if (!isused[i]) {
				isused[i] = 1;
				numbers[used_numbers] = i;
				used_numbers++;
				set_edge(num_max, num);
				if (find_ans) break;
				isused[i] = 0;
				used_numbers--;
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> h;
	width = n * 2 - 1;
	for (int i = 0; i < width; i+=2) {
		for (int j = 0; j < h; j++) {
			board[j][i] = 1;
		}
	}
	
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		b = 2 * b + 1;
		board[a][b] = 1;
	}

	
	int num_max = (n - 1) * h;
	for (int i = 0; i < 4; i++) {
		set_edge(num_max, i);
		if (find_ans == 1) break;
	}
	

	if (find_ans) {
		cout << ans;
	}
	else {
		cout << -1;
	}

	return 0;
}