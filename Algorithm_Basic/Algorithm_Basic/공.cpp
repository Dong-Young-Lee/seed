#include <iostream>
#include <vector>
using namespace std;

vector<bool> cup(3, false);
int main(void) {
	int m;
	cin >> m;
	cup[0] = true;
	while (m--) {
		int x, y;
		cin >> x >> y;
		if (x == y) continue;
		else {
			if (cup[x - 1]) {
				cup[x - 1] = false;
				cup[y - 1] = true;
			}
			else if(cup[y - 1]) {
				cup[y - 1] = false;
				cup[x - 1] = true;
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		if (cup[i]) {
			cout << i + 1;
		}
	}

	return 0;
}