#include <iostream>
#include <vector>
using namespace std;

vector< pair<int, int> > train;

int main(void) {
	for (int i = 0; i < 4; i++) {
		int out, in;
		cin >> out >> in;
		train.push_back(make_pair(out, in));
	}

	int ans = 0;
	int cur_cnt = 0;
	for (int i = 0; i < 4; i++) {
		cur_cnt -= train[i].first;
		cur_cnt += train[i].second;

		if (ans < cur_cnt) {
			ans = cur_cnt;
		}
	}

	cout << ans;

	return 0;
}