#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <deque>
using namespace std;

const int number_of_gears = 4;

void rotate(vector< deque<int> > &dq_right, vector< deque<int> > &dq_left, int gear_num, int direction) {
	if (direction == 1) { // �ð�
		dq_right[gear_num].push_front(dq_left[gear_num].back());
		dq_left[gear_num].pop_back();
		dq_left[gear_num].push_front(dq_right[gear_num].back());
		dq_right[gear_num].pop_back();
	}
	else { // �ݽð�
		dq_right[gear_num].push_back(dq_left[gear_num].front());
		dq_left[gear_num].pop_front();
		dq_left[gear_num].push_back(dq_right[gear_num].front());
		dq_right[gear_num].pop_front();
	}
}

void search_chain(vector< deque<int> > &dq_right, vector< deque<int> > &dq_left, int gear_num, int direction) {
	gear_num--;
	deque<int> dq;
	// �ϴ� ��ü�� ���ư�
	dq.push_back(gear_num);

	int left_num = 0;
	// �������� Ȯ��
	for (int i = gear_num - 1; i >= 0; i--) {
		if (dq_right[i].front() != dq_left[i + 1].front()) { // ���� �ٸ�
			left_num++;
			dq.push_front(i);
		}
		else {
			break;
		}
	}

	// ���������� Ȯ��
	for (int i = gear_num + 1; i < number_of_gears; i++) {
		if (dq_left[i].front() != dq_right[i - 1].front()) { // ���� �ٸ�
			dq.push_back(i);
		}
		else {
			break;
		}
	}

	// ȸ��
	if (left_num % 2 == 0) {
		while (!dq.empty()) {
			rotate(dq_right, dq_left, dq.front(), direction);
			dq.pop_front();
			direction *= -1;
		}
	}
	else {
		while (!dq.empty()) {
			direction *= -1;
			rotate(dq_right, dq_left, dq.front(), direction);
			dq.pop_front();
		}
	}


}

int main(void) {
	vector< deque<int> > dq_right(4);
	vector< deque<int> > dq_left(4);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			int p;
			scanf("%1d", &p);
			if (j >= 2 && j <= 5) {
				dq_right[i].push_back(p);
			}
			else {
				dq_left[i].push_back(p);
			}
		}
		for (int j = 0; j < 2; j++) {
			dq_left[i].push_back(dq_left[i].front());
			dq_left[i].pop_front();
		}
	}

	int n;
	scanf("%d", &n);
	while (n--) {
		int gear_num, direction;
		scanf("%d %d", &gear_num, &direction);
		search_chain(dq_right, dq_left, gear_num, direction);
	}

	int ans = 0;
	for (int i = 0; i < number_of_gears; i++) {
		dq_left[i].pop_back();
		if (dq_left[i].back() == 1) {
			ans += (1 << i);
		}
	}

	printf("%d", ans);

	return 0;
}