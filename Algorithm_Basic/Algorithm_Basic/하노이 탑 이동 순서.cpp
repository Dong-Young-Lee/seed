#include <iostream>
using namespace std;

// n개의 원판을
// 기둥 start 에서
// 기둥 dest 로
void func(int start, int dest, int n) {
	// base condition
	if (n == 1) {
		cout << start << ' ' << dest << '\n';
		return;
	}

	// start, dest가 아닌 기둥 extra
	int extra = 6 - start - dest;

	func(start, extra, n - 1);
	cout << start << ' ' << dest << '\n';
	func(extra, dest, n - 1);

}

int main(void) {
	int n;
	cin >> n;

	func(1, 3, n);


	return 0;
}