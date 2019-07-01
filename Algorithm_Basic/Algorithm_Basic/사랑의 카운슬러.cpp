#include <iostream>
#include <vector>
using namespace std;

int tc, n;
vector< pair<int, int> > input;

int main(void) {
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n;

		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			input.push_back(make_pair(x, y));
		}



	}

	return 0;
}