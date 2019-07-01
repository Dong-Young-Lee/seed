#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

vector<int> vec(100);

int n;

int main(void) {
	cin >> n;

	int max_int = 0;

	for (int i = 0; i < n; i++) {
		cin >> vec[i];
		if (max_int < vec[i]) {
			max_int = vec[i];
		}
	}

	int ans = 1000000000;

	for (int i = 0; i <= max_int; i++) {
		int temp = 0;
		for (int j = 0; j < n; j++) {
			int dis = vec[j] - i;
			if (dis < 0) {
				dis = -dis;
			}

			temp += dis;

		}
		if (ans > temp) {
			ans = temp;
		}
	}

	cout << ans;


	return 0;
}