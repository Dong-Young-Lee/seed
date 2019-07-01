#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int input[8];

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	sort(input, input + n);

	do {
		for (int i = 0; i < m; i++) {
			cout << input[i] << ' ';
		}
		cout << '\n';
		reverse(input + m, input + n);
	} while (next_permutation(input, input + n));

	return 0;
}




/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int input[8];

int isused[8];
vector<int> numbers;
int used_numbers;

vector< vector<int> > permutation;

void func() {
	if (used_numbers == m) {
		int perm_size = permutation.size();
		if (perm_size == 0) {
			permutation.push_back(numbers);
			for (int i = 0; i < m; i++) {
				cout << numbers[i] << ' ';
			}
			cout << '\n';
			return;
		}
		else {
			for (int i = 0; i < perm_size; i++) {
				int duplicate = 1;
				for (int j = 0; j < m; j++) {
					if (numbers[j] != permutation[i][j]) {
						duplicate = 0;
						break;
					}
				}
				if (duplicate) return;
			}
		}

		permutation.push_back(numbers);
		for (int i = 0; i < m; i++) {
			cout << numbers[i] << ' ';
		}
		cout << '\n';

		return;
	}

	for (int i = 0; i < n; i++) {
		if (!isused[i]) {
			isused[i] = 1;
			numbers.push_back(input[i]);
			used_numbers++;
			func();
			isused[i] = 0;
			numbers.pop_back();
			used_numbers--;
		}
	}

}

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	sort(input, input + n);

	func();

	return 0;
}
*/