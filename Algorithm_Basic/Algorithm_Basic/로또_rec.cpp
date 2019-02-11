#include <iostream>
#include <vector>
using namespace std;

vector<int> select;

void solve(vector<int> &input, int n, int count, int index) {
	// 2. 정답인 경우
	if (count == n) {
		for (int num : select) {
			cout << num << ' ';
		}
		cout << '\n';
		return;
	}

	// 1. 불가능한 경우
	if (index == input.size()) {
		return;
	}

	// 3. top-down
	// 3-1. 수를 선택하는 경우
	select.push_back(input[index]);
	solve(input, n, count + 1, index + 1);
	// 3-2. 수를 선택하지 않는 경우
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