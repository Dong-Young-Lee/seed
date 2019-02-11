/*

< recursive function >

1. 불가능한 경우
2. 정답을 찾은 경우
3. 다음 경우 호출

*/

#include <iostream>
using namespace std;

int solve(int n, int sum) {
	if (sum > n) return 0;
	if (sum == n) return 1;
	int count = 0; // 여기서 선언! 중요!

	for (int i = 1; i <= 3; i++) {
		count += solve(n, sum + i);
	}

	return count; // 모아서 올려 보냄!
}

int main(void) {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		int sum = 0;
		cout << solve(n, sum) << '\n';
	}

	return 0;
}