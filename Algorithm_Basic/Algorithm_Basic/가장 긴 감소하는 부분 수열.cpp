#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> d(1001, -1);
vector<int> seq(1001);

int main(void) {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> seq[i];
	}

	d[1] = 1;
	
	for (int i = 2; i <= n; i++) {
		d[i] = 1;
		for (int j = 1; j < i; j++) {
			if (seq[j] > seq[i]) {
				if (d[j]+1 > d[i]) {
					d[i] = d[j] + 1;
				}
			}
		}
	}

	cout << *max_element(d.begin(), d.end());

	return 0;
}