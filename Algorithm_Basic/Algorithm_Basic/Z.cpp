#include <iostream>
using namespace std;

int n, r, c;
int ans = 0;

void func(int size, int row, int col) {
	// base condition
	if (size == 2) {
		if (row == r && col == c) {
			cout << ans;
			return;
		}
		else if (row == r && col + 1 == c) {
			cout << ans + 1;
			return;
		}
		else if (row + 1 == r && col == c) {
			cout << ans + 2;
			return;
		}
		else if (row + 1 == r && col + 1 == c) {
			cout << ans + 3;
			return;
		}
		else {
			ans += 4;
			return;
		}
	}
	
	// left up
	func(size / 2, row, col);
	// right up
	func(size / 2, row, col + size / 2);
	// left down
	func(size / 2, row + size / 2, col);
	// right down
	func(size / 2, row + size / 2, col + size / 2);

}

int main(void) {
	cin >> n >> r >> c;
	int size = (1 << n);
	func(size, 0, 0);

	return 0;
}