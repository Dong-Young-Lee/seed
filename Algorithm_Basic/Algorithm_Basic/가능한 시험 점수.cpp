#include <iostream>
using namespace std;

const int MAX = 100;

int tc, n;
int map[MAX];

int solve() {
	int score[10001] = { 0, };

	score[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 10000; j >= 0; j--) {
			if (score[j]) {
				score[j + map[i]] = 1;
			}
		}
	}
	int ret = 0;

	for (int i = 0; i < 10001; i++) {
		if (score[i]) ret++;
	}
	return ret;
}

int main(void) {
	cin >> tc;
	for (int t = 1; t <= tc; t++) {

		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> map[i];
		}

		cout << '#' << t << ' ' << solve() << '\n';

	}
	return 0;
}

//#include <iostream>
//#include <string.h>
//using namespace std;
//
//const int MAX = 100;
//
//int tc, n;
//int map[MAX];
//int score[10001];
//int ans;
//
//void dfs(int index, int sco) {
//	score[sco] = 1;
//
//	if (index == n) {
//		return;
//	}
//
//	dfs(index + 1, sco + map[index]);
//	dfs(index + 1, sco);
//}
//
//int main(void) {
//	cin >> tc;
//	for (int t = 1; t <= tc; t++) {
//		memset(score, 0, sizeof(score));
//		ans = 0;
//
//		cin >> n;
//		for (int i = 0; i < n; i++) {
//			cin >> map[i];
//		}
//
//
//		dfs(0, 0);
//
//		for (int i = 0; i < 10001; i++) {
//			if (score[i]) ans++;
//		}
//
//		cout << '#' << t << ' ' << ans << '\n';
//
//	}
//	return 0;
//}