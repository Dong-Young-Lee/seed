#include <iostream>
#include <vector>
using namespace std;

int ans = 0;

void solve(vector<int> &input, int s, int sum, int index, int count) {
	if (sum == s && count) {
		ans += 1;
		return;
	}
	int length = input.size();
	if (index >= length) {
		return;
	}

	// 3. top-down
	// ���� �ε����� ���ϴ� ���
	solve(input, s, sum + input[index], index + 1, 1);
	// ���� �ε����� ������ �ʴ� ���
	solve(input, s, sum, index + 1, 0);

}

int main(void) {
	int n, s;
	cin >> n >> s;

	vector<int> input(n);
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	solve(input, s, 0, 0, 0);
	//if (s == 0) ans -= 1; // ������ ����
	cout << ans;

	return 0;
}