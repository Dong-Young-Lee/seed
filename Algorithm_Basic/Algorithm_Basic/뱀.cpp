#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <deque>
using namespace std;

int n;
vector< vector<int> > matrix(100, vector<int>(100, 0));
int k;
int c;
vector<char> direction(100001);
deque< pair<int, int> > dq;

// 위 오른쪽 아래 왼쪽
int d_r[4] = { -1, 0, 1, 0 };
int d_c[4] = { 0, 1, 0, -1 };

int main(void) {
	scanf("%d", &n);
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int r, c;
		scanf("%d %d", &r, &c);
		matrix[r-1][c-1] = 1; // 사과 : 1
	}
	
	scanf("%d", &c);
	for (int i = 0; i < c; i++) {
		int t;
		char com;
		scanf("%d %c", &t, &com);
		
		direction[t] = com;
	}

	matrix[0][0] = -1;

	int time = 0;
	dq.push_back(make_pair(0, 0));
	int cur_dir = 1; // 오른쪽

	while (true) {
		// 시간 증가
		time++;
		// 머리 위치
		int head_row = dq.front().first;
		int head_col = dq.front().second;

		// 꼬리 위치
		int tail_row = dq.back().first;
		int tail_col = dq.back().second;

		// 뱀 이동
		if (cur_dir == 0) { // 위
			head_row += d_r[0];
			head_col += d_c[0];
		}
		else if (cur_dir == 1) { // 오른쪽
			head_row += d_r[1];
			head_col += d_c[1];
		}
		else if (cur_dir == 2) { // 아래
			head_row += d_r[2];
			head_col += d_c[2];
		}
		else { // 왼쪽
			head_row += d_r[3];
			head_col += d_c[3];
		}
		
		// 다음 칸이 벽이라면
		if (head_row < 0 || head_row == n || head_col < 0 || head_col == n) {
			printf("%d", time);
			break;
		}

		// 이동위치에 사과가 있다면 꼬리 지우지 않음
		if (matrix[head_row][head_col] == 1) { // 사과 먹음
			matrix[head_row][head_col] = -1;
			dq.push_front(make_pair(head_row, head_col)); // 머리 추가
			
		}
		else if (matrix[head_row][head_col] == -1) { // 다음칸이 몸통
			printf("%d", time);
			break;
		}
		else { // 그냥 이동
			matrix[head_row][head_col] = -1;
			dq.push_front(make_pair(head_row, head_col)); // 머리 추가
			matrix[tail_row][tail_col] = 0;
			dq.pop_back(); // 꼬리 지움
		}

		// t 초에 방향 변화가 있는지 확인
		if (direction[time] == 'L') { // 왼쪽 90도
			cur_dir -= 1;
			if (cur_dir == -1) {
				cur_dir = 3;
			}
		}
		else if (direction[time] == 'D') { // 오른쪽 90도
			cur_dir += 1;
			if (cur_dir == 4) {
				cur_dir = 0;
			}
		}
	}

	return 0;
}