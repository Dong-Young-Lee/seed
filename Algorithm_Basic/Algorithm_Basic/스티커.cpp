/*
정해진 순서가 없지만 순서는 만들면 된다.
* DP문제는 브루트포스로 풀 수 있다.
* 브루트포스는 모든 경우의 수를 보는 것

*중요* 이 문제가 DP문제인 이유?
...

행은 2행으로 고정되어 있고, 열이 유동적이니
1열부터 n열까지 dp를 채워나가면 된다.

각 열마다 선택지가 총 3개가 있다.

 0. 뜯지 않는다.
 1. 위쪽 스티커를 뜯는다.
 2. 아래쪽 스티커를 뜯는다.

 위 선택지는 이 전에 뜯은 선택에 영향을 받는다.
 
 d[n][last] : 마지막 선택이 last인 n열까지 뗀 스티커 
 stk[i][j] : 스티커의 점수
 
 d[n][0] = max(d[n-1][0], d[n-1][1], d[n-1][2])
 d[n][1] = max(d[n-1][0], d[n-1][2]) + stk[0][n]
 d[n][2] = max(d[n-1][0], d[n-1][1]) + stk[1][n]

 각각 subproblem을 풀며 problem을 구하고 
 마지막에 최댓값을 구해준다.
 ans = max(d[n][0], d[n][1], d[n][2])

 < 중요 >
 중요한 건 이 문제가 dp문제인지 파악하는 것이고,
 d를 정하고, 구하는 방법이 중요하다.
 여기서는 고정적인 것과 가변적인 것을 알고 가변에 초점을 두자.
*/

// bottom-up
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector< vector<int> > d(100001, vector<int>(3, -1));
vector< vector<int> > stk(2, vector<int>(100001, 0));

int main(void) {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> stk[0][i];
		}
		for (int i = 1; i <= n; i++) {
			cin >> stk[1][i];
		}

		// 1. 초기값 저장
		d[1][0] = 0, d[1][1] = stk[0][1], d[1][2] = stk[1][1];

		// 2. dp
		for (int i = 2; i <= n; i++) {
			d[i][0] = max(max(d[i - 1][0], d[i - 1][1]), d[i - 1][2]);
			d[i][1] = max(d[i - 1][0], d[i - 1][2]) + stk[0][i];
			d[i][2] = max(d[i - 1][0], d[i - 1][1]) + stk[1][i];
		}

		// 3. 최종해 구하기
		cout << max(max(d[n][0], d[n][1]), d[n][2]) << '\n';

	}

	return 0;
}

// top-down
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector< vector<int> > d(100001, vector<int>(4, -1));
vector< vector<int> > stk(2, vector<int>(100001, 0));

int solve(int n, int last) {
	// 2. 초기값 리턴
	if (n == 1) return d[n][last];

	// 3. 해가 저장되어 있으면 리턴
	if (d[n][last] != -1) return d[n][last];

	// 4. dp
	d[n][0] = max(max(solve(n - 1, 0), solve(n - 1, 1)), solve(n - 1, 2));
	d[n][1] = max(solve(n - 1, 0), solve(n - 1, 2)) + stk[0][n];
	d[n][2] = max(solve(n - 1, 0), solve(n - 1, 1)) + stk[1][n];

	// 5. 최종 해 구하기
	d[n][3] = max(max(d[n][0], d[n][1]), d[n][2]);

	return d[n][last];
}

int main(void) {
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		// 테스트 케이스 초기화
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= 3; j++) {
				d[i][j] = -1;
			}
		}

		for (int i = 1; i <= n; i++) {
			cin >> stk[0][i];
		}
		for (int i = 1; i <= n; i++) {
			cin >> stk[1][i];
		}

		// 1. 초기값 저장
		d[1][0] = 0, d[1][1] = stk[0][1], d[1][2] = stk[1][1];

		cout << solve(n, 3) << '\n';

	}
	return 0;
}