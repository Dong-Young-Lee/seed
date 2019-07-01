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
		cnt++; // 주사위를 던짐
		int number = dice[cnt]; // 던져서 나온 숫자
		int next_position = cur_position + number; // 다음 칸
		cur_position = next_position + board[next_position]; // 지시 사항을 따른 포지션
		if (cur_position >= n - 1) {
			cout << cnt + 1;
			break;
		}
	}
	return 0;
}