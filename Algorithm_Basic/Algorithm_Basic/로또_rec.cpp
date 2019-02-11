#include <iostream>
#include <vector>
using namespace std;

vector<int> select;

void solve(vector<int> &input, int n, int count, int index) {
	// 2. ������ ���
	if (count == n) {
		for (int num : select) {
			cout << num << ' ';
		}
		cout << '\n';
		return;
	}

	// 1. �Ұ����� ���
	if (index == input.size()) {
		return;
	}

	// 3. top-down
	// 3-1. ���� �����ϴ� ���
	select.push_back(input[index]);
	solve(input, n, count + 1, index + 1);
	// 3-2. ���� �������� �ʴ� ���
	select.pop_back();
	solve(input, n, count, index + 1);
}

int main(void) {
	int n;
	while (cin >> n) {
		if (n == 0) break;

		vector<int> input(n);
		for (int i = 0; i < n; i++) {
			cin >> input[i];
		}

		solve(input, 6, 0, 0);
		cout << '\n';
		
	}
	return 0;
}