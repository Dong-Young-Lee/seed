// bottom-up
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> btn(1001, -1);
vector<int> incr(1001, 1);
vector<int> decr(1001, 1);

vector<int> seq(1001);

int main(void) {
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> seq[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (seq[i] > seq[j]) {
				if (incr[j] + 1 > incr[i]) {
					incr[i] = incr[j] + 1;
				}
			}
		}
	}

	for (int i = n; i >= 1; i--) {
		for (int j = n; j > i; j--) {
			if (seq[i] > seq[j]) {
				if (decr[j] + 1 > decr[i]) {
					decr[i] = decr[j] + 1;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		btn[i] += (incr[i] + decr[i]);
	}

	cout << *max_element(btn.begin(), btn.end()) << '\n';

	return 0;
}