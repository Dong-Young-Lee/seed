#include <iostream>
#include <vector>
using namespace std;

int n;
bool isused1[14];
bool isused2[29];
bool isused3[29];
int cnt;

void func(int cur) { // 현재 퀸의 개수이자, 현재 row
	if (cur == n) {
		cnt++;
		return;
	}
	for (int i = 0; i < n; i++) { // column 확인
		if (isused1[i] || isused2[i + cur] || isused3[i - cur + n]) continue;
		isused1[i] = 1;
		isused2[i + cur] = 1;
		isused3[i - cur + n] = 1;
		func(cur + 1);
		isused1[i] = 0;
		isused2[i + cur] = 0;
		isused3[i - cur + n] = 0;
	}
}


int main(void) {
	cin >> n;

	func(0);
	cout << cnt;
	return 0;
}
