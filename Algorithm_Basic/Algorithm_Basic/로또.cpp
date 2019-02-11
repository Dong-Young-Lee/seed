#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main(void) {
	int n;
	while (cin >> n) {
		if (n == 0) break;
		else {
			vector<int> input(n);
			for (int i = 0; i < n; i++) {
				cin >> input[i];
			}

			vector<int> select(n);
			for (int i = 0; i < n; i++) {
				if (i < 6) { 
					select[i] = 0;
				}
				else {
					select[i] = 1;
				}
			}
			
			do {
				for (int i = 0; i < n; i++) {
					if (select[i] == 0) {
						cout << input[i] << ' ';
					}
				}
				cout << '\n';
			} while (next_permutation(select.begin(), select.end()));
			cout << '\n';
		}
	}
	return 0;
}