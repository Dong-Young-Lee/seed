#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int x;
	cin >> x;
	vector<int> stick;

	// exception
	if (x == 64) {
		cout << 1;
		return 0;
	}

	stick.push_back(64);

	while (true) {
		// ������ �ִ� ���� �� ���̰� ���� ª�� ���� ����.
		int min_stick = 65;
		int min_stick_index;
		for (int i = 0; i < (int)stick.size(); i++) {
			if (min_stick > stick[i]) {
				min_stick = stick[i];
				min_stick_index = i;
			}
		}

		// �������� �ڸ���.
		int half_min_stick = min_stick / 2;
		
		// �߷��� ���븦 ��������
		vector<int> temp;
		for (int i = 0; i < (int)stick.size() - min_stick_index; i++) {
			temp.push_back(stick.back());
			stick.pop_back();
		}
		temp.pop_back();
		for (int i = 0; i < (int)temp.size(); i++) {
			stick.push_back(temp.back());
			temp.pop_back();
		}

		// �ϴ� �ڸ� ����1�� ����
		stick.push_back(half_min_stick);

		// ���� �ڸ� ������ ���� �� �ϳ��� ������, 
		// �����ִ� ������ ������ ���� X���� ũ�ų� ���ٸ�,
		// ������ �ڸ� ������ ���� �� �ϳ��� ������.
		int temp_sum = 0;
		for (int i = 0; i < (int)stick.size(); i++) {
			temp_sum += stick[i];
		}

		// �ƴϸ� �ڸ� ����2�� �� �־���
		if (temp_sum < x) {
			stick.push_back(half_min_stick);

		}

		// ������ ��� ���
		if (temp_sum == x) {
			cout << stick.size();
			break;
		}
		
	}
	
	return 0;
}