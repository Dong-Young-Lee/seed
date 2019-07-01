#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> board(2000);
vector<int> dice(1000);

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> dice[i];
	}

	int cur_position = 0;
	int cnt = -1;
	while (true) {
		cnt++; // �ֻ����� ����
		int number = dice[cnt]; // ������ ���� ����
		int next_position = cur_position + number; // ���� ĭ
		cur_position = next_position + board[next_position]; // ���� ������ ���� ������
		if (cur_position >= n - 1) {
			cout << cnt + 1;
			break;
		}
	}
	return 0;
}