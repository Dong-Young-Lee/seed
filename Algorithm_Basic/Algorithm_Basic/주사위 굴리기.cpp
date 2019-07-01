#include <iostream>
#include <vector>
using namespace std;

int n, m, x, y, k;
vector< vector<int> > map(20, vector<int>(20));

// ��0 ��1 ��2 ��3
int d_row[4] = { 0, 0, -1, 1 };
int d_col[4] = { 1, -1, 0, 0 };

// �� �� �� �� �� �Ʒ�
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
		if (command == 1) { // ����
			cur_row += d_row[0];
			cur_col += d_col[0];
			if (cur_row >= 0 && cur_row < n && cur_col >= 0 && cur_col < m) {
				int temp = dice[1];
				dice[1] = dice[5]; // �� = �Ʒ�
				if (map[cur_row][cur_col] == 0) {
					map[cur_row][cur_col] = dice[0];
					dice[5] = dice[0];
				}
				else {
					dice[5] = map[cur_row][cur_col]; // �Ʒ�
					map[cur_row][cur_col] = 0;
				}
				dice[0] = dice[4]; // �� = ��
				dice[4] = temp; // �� = ��
				cout << dice[4] << '\n';
			}
			else {
				cur_row -= d_row[0];
				cur_col -= d_col[0];
			}
			
		}
		else if (command == 2) { // ����
			cur_row += d_row[1];
			cur_col += d_col[1];
			if (cur_row >= 0 && cur_row < n && cur_col >= 0 && cur_col < m) {
				int temp = dice[0];
				dice[0] = dice[5]; // �� = �Ʒ�
				if (map[cur_row][cur_col] == 0) {
					map[cur_row][cur_col] = dice[1];
					dice[5] = dice[1];
				}
				else {
					dice[5] = map[cur_row][cur_col]; // �Ʒ�
					map[cur_row][cur_col] = 0;
				}
				dice[1] = dice[4]; // �� = ��
				dice[4] = temp; // �� = ��
				cout << dice[4] << '\n';
			}
			else {
				cur_row -= d_row[1];
				cur_col -= d_col[1];
			}
		}
		else if (command == 3) { // ����
			cur_row += d_row[2];
			cur_col += d_col[2];
			if (cur_row >= 0 && cur_row < n && cur_col >= 0 && cur_col < m) {
				int temp = dice[2];
				dice[2] = dice[5]; // �� = �Ʒ�
				if (map[cur_row][cur_col] == 0) {
					map[cur_row][cur_col] = dice[3];
					dice[5] = dice[3];
				}
				else {
					dice[5] = map[cur_row][cur_col]; // �Ʒ�
					map[cur_row][cur_col] = 0;
				}
				dice[3] = dice[4]; // �� = ��
				dice[4] = temp; // �� = ��
				cout << dice[4] << '\n';
			}
			else {
				cur_row -= d_row[2];
				cur_col -= d_col[2];
			}
		}
		else { // ����
			cur_row += d_row[3];
			cur_col += d_col[3];
			if (cur_row >= 0 && cur_row < n && cur_col >= 0 && cur_col < m) {
				int temp = dice[3];
				dice[3] = dice[5]; // �� = �Ʒ�
				if (map[cur_row][cur_col] == 0) {
					map[cur_row][cur_col] = dice[2];
					dice[5] = dice[2];
				}
				else {
					dice[5] = map[cur_row][cur_col]; // �Ʒ�
					map[cur_row][cur_col] = 0;
				}
				dice[2] = dice[4]; // �� = ��
				dice[4] = temp; // �� = ��
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