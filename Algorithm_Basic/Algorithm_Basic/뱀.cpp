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

// �� ������ �Ʒ� ����
int d_r[4] = { -1, 0, 1, 0 };
int d_c[4] = { 0, 1, 0, -1 };

int main(void) {
	scanf("%d", &n);
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int r, c;
		scanf("%d %d", &r, &c);
		matrix[r-1][c-1] = 1; // ��� : 1
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
	int cur_dir = 1; // ������

	while (true) {
		// �ð� ����
		time++;
		// �Ӹ� ��ġ
		int head_row = dq.front().first;
		int head_col = dq.front().second;

		// ���� ��ġ
		int tail_row = dq.back().first;
		int tail_col = dq.back().second;

		// �� �̵�
		if (cur_dir == 0) { // ��
			head_row += d_r[0];
			head_col += d_c[0];
		}
		else if (cur_dir == 1) { // ������
			head_row += d_r[1];
			head_col += d_c[1];
		}
		else if (cur_dir == 2) { // �Ʒ�
			head_row += d_r[2];
			head_col += d_c[2];
		}
		else { // ����
			head_row += d_r[3];
			head_col += d_c[3];
		}
		
		// ���� ĭ�� ���̶��
		if (head_row < 0 || head_row == n || head_col < 0 || head_col == n) {
			printf("%d", time);
			break;
		}

		// �̵���ġ�� ����� �ִٸ� ���� ������ ����
		if (matrix[head_row][head_col] == 1) { // ��� ����
			matrix[head_row][head_col] = -1;
			dq.push_front(make_pair(head_row, head_col)); // �Ӹ� �߰�
			
		}
		else if (matrix[head_row][head_col] == -1) { // ����ĭ�� ����
			printf("%d", time);
			break;
		}
		else { // �׳� �̵�
			matrix[head_row][head_col] = -1;
			dq.push_front(make_pair(head_row, head_col)); // �Ӹ� �߰�
			matrix[tail_row][tail_col] = 0;
			dq.pop_back(); // ���� ����
		}

		// t �ʿ� ���� ��ȭ�� �ִ��� Ȯ��
		if (direction[time] == 'L') { // ���� 90��
			cur_dir -= 1;
			if (cur_dir == -1) {
				cur_dir = 3;
			}
		}
		else if (direction[time] == 'D') { // ������ 90��
			cur_dir += 1;
			if (cur_dir == 4) {
				cur_dir = 0;
			}
		}
	}

	return 0;
}