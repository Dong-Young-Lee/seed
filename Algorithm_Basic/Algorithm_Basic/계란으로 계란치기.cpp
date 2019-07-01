#include <iostream>
#include <vector>
using namespace std;

int n;
vector< pair<int, int> > egg;
int ans;

int isused[8];

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		egg.push_back(make_pair(a, b));
	}


	return 0;
}

