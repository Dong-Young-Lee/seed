/*
d[n]�� n�� ���������� ������ ǥ���� �� �ִ� ���� �ּ� ����
������ �׿� �����Ѵ�.

*/



#include <iostream>
#include <vector>
using namespace std;

// �ʱ�ȭ ����!!
vector<int> d(100001, 0);

int main(void) {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		// ���� ū ���� ������ ��� 1�� �̷�� �� ��
		d[i] = i;
		for (int j = 1; (j*j) <= i; j++) {
			// �ּ� ���� ���� ã��
			if (d[i] > d[i - (j * j)] + 1) {
				d[i] = d[i - (j * j)] + 1;
			}
		}
	}

	cout << d[n];

	return 0;
}