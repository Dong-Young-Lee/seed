#include <iostream>
using namespace std;

// n���� ������
// ��� start ����
// ��� dest ��
void func(int start, int dest, int n) {
	// base condition
	if (n == 1) {
		cout << start << ' ' << dest << '\n';
		return;
	}

	// start, dest�� �ƴ� ��� extra
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