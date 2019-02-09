// bottom-up
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// d[n]�� seq���� n��° ���� ������ 
// ���� �κ� �����߿��� ���� ���� ū ��
vector<int> d(1001, -1);
vector<int> seq(1001);

int main(void) {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> seq[i];
	}

	// 1. �ʱⰪ ����
	for (int i = 1; i <= n; i++) {
		d[i] = seq[i];
	}

	// 2. dp
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (seq[i] > seq[j]) {
				if (d[j] + seq[i] > d[i]) {
					d[i] = d[j] + seq[i];
				}
			}
		}
	}

	cout << *max_element(d.begin(), d.end());

	return 0;
}