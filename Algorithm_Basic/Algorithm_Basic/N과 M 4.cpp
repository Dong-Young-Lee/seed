#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> numbers;
int used_numbers;

void func() {
	if (used_numbers == m) {
		for (int i = 1; i <= m; i++) {
			cout << numbers[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		if (numbers[used_numbers] <= i + 1) {
			numbers.push_back(i + 1);
			used_numbers++;
			func();
			numbers.pop_back();
			used_numbers--;
		}
	}
}

int main(void) {
	cin >> n >> m;
	
	numbers.push_back(0);
	func();
	
	return 0;
}