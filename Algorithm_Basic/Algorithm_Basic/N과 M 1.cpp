// Backtracking
#include <iostream>
#include <vector>
using namespace std;

int n, m;

bool isused[8];
vector<int> numbers;
int used_numbers;

void func() {
	// base condition
	if (used_numbers == m) {
		for (int i = 0; i < m; i++) {
			cout << numbers[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		if (isused[i] == false) {
			isused[i] = true;
			numbers.push_back(i + 1);
			used_numbers++;
			func();
			isused[i] = false;
			numbers.pop_back();
			used_numbers--;
		}
	}
}

int main(void) {
	cin >> n >> m;
	
	func();

	return 0;
}

// Permutation
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int n, m;
//int main(void) {
//	cin >> n, m;
//	vector<int> numbers(n);
//	for (int i = 0; i < n; i++) {
//		numbers.push_back(i + 1);
//	}
//	vector<int> selection;
//	for (int i = 0; i < n - m; i++) {
//		selection.push_back(0);
//	}
//	for (int i = 0; i < m; i++) {
//		selection.push_back(1);
//	}
//
//	do {
//		vector<int> current;
//		for (int i = 0; i < n; i++) {
//			if (selection[i] == 1) {
//				current.push_back(numbers[i]);
//			}
//		}
//
//		for (int i = 0; i < m; i++) {
//			cout << current[i] << ' ';
//		}
//		cout << '\n';
//	} while (next_permutation(selection.begin(), selection.end()));
//	
//
//	return 0;
//}