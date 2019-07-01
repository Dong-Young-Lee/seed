#include <iostream>
using namespace std;

int t;
int tri_num[45];
int k;

int flag;
void func(int index, int sum, int used_numbers) {
	if (flag == 1) {
		return;
	}
	
	if (sum > k || index > 44 || used_numbers > 3) {
		return;
	}
	
	if (sum != k && used_numbers == 3) {
		return;
	}

	if (sum == k && used_numbers == 3) {
		flag = 1;
		return;
	}

	// 중복되게 더하면서
	func(index, sum + tri_num[index], used_numbers + 1);
	// 더하면서 다음꺼 중복 X
	func(index + 1, sum + tri_num[index], used_numbers + 1);
	// 더하지 않고 다음꺼
	func(index + 1, sum, used_numbers);
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 1; i < 45; i++) {
		tri_num[i] = i * (i + 1) / 2;
	}

	cin >> t;
	while (t--) {
		cin >> k;

		flag = 0;
		func(1, 0, 0);

		if (flag) {
			cout << 1 << '\n';
		}
		else {
			cout << 0 << '\n';
		}
	}
	return 0;
}