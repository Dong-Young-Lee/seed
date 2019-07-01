#include <iostream>
#include <vector>
using namespace std;

int n, m, x, y, k;
vector< vector<int> > map(20, vector<int>(20));

// 동0 서1 북2 남3
int d_row[4] = { 0, 0, -1, 1 };
int d_col[4] = { 1, -1, 0, 0 };

// 동 서 남 북 위 아래
vector<int> dice(6, 0);

int main(void) {
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	int cur_row = x;
	int cur_col = y;

	int command;
	for (int i = 0; i < k; i++) {
		cin >> command;
		if (command == 1) { // 동쪽
			cur_row += d_row[0];
			cur_col += d_col[0];
			if (cur_row >= 0 && cur_row < n && cur_col >= 0 && cur_col < m) {
				int temp = dice[1];
				dice[1] = dice[5]; // 서 = 아래
				if (map[cur_row][cur_col] == 0) {
					map[cur_row][cur_col] = dice[0];
					dice[5] = dice[0];
				}
				else {
					dice[5] = map[cur_row][cur_col]; // 아래
					map[cur_row][cur_col] = 0;
				}
				dice[0] = dice[4]; // 동 = 위
				dice[4] = temp; // 위 = 서
				cout << dice[4] << '\n';
			}
			else {
				cur_row -= d_row[0];
				cur_col -= d_col[0];
			}
			
		}
		else if (command == 2) { // 서쪽
			cur_row += d_row[1];
			cur_col += d_col[1];
			if (cur_row >= 0 && cur_row < n && cur_col >= 0 && cur_col < m) {
				int temp = dice[0];
				dice[0] = dice[5]; // 동 = 아래
				if (map[cur_row][cur_col] == 0) {
					map[cur_row][cur_col] = dice[1];
					dice[5] = dice[1];
				}
				else {
					dice[5] = map[cur_row][cur_col]; // 아래
					map[cur_row][cur_col] = 0;
				}
				dice[1] = dice[4]; // 서 = 위
				dice[4] = temp; // 위 = 동
				cout << dice[4] << '\n';
			}
			else {
				cur_row -= d_row[1];
				cur_col -= d_col[1];
			}
		}
		else if (command == 3) { // 북쪽
			cur_row += d_row[2];
			cur_col += d_col[2];
			if (cur_row >= 0 && cur_row < n && cur_col >= 0 && cur_col < m) {
				int temp = dice[2];
				dice[2] = dice[5]; // 남 = 아래
				if (map[cur_row][cur_col] == 0) {
					map[cur_row][cur_col] = dice[3];
					dice[5] = dice[3];
				}
				else {
					dice[5] = map[cur_row][cur_col]; // 아래
					map[cur_row][cur_col] = 0;
				}
				dice[3] = dice[4]; // 북 = 위
				dice[4] = temp; // 위 = 남
				cout << dice[4] << '\n';
			}
			else {
				cur_row -= d_row[2];
				cur_col -= d_col[2];
			}
		}
		else { // 남쪽
			cur_row += d_row[3];
			cur_col += d_col[3];
			if (cur_row >= 0 && cur_row < n && cur_col >= 0 && cur_col < m) {
				int temp = dice[3];
				dice[3] = dice[5]; // 북 = 아래
				if (map[cur_row][cur_col] == 0) {
					map[cur_row][cur_col] = dice[2];
					dice[5] = dice[2];
				}
				else {
					dice[5] = map[cur_row][cur_col]; // 아래
					map[cur_row][cur_col] = 0;
				}
				dice[2] = dice[4]; // 남 = 위
				dice[4] = temp; // 위 = 북
				cout << dice[4] << '\n';
			}
			else {
				cur_row -= d_row[3];
				cur_col -= d_col[3];
			}
		}
	}
	return 0;
}