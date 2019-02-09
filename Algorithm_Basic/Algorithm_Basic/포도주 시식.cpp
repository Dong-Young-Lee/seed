// 유사문제 : 이친수

/*
d[n] : n번째 줄까지 놓여있는 포도주를 마신 최대량
grape[n] : n번째 줄의 포도주의 양

<조건 1> : 연속으로 놓여 있는 3잔을 모두 마실 수는 없다.
여기서 '연속'이라는 조건을 확인 하려면
d[n][t] : 마지막 n번째 줄까지 연속으로 t만큼 마신 포도주를 마신 최대량
t의 범위 : ( 0 <= t <= 2 )


n-1번째 까지 마신 최대량에서 n번째에 선택은 2가지가 있다.
1. 마시지 않는다.
2. 마신다.

여기서 <조건 1>을 고려하여 점화식을 구하면
1. 마시지 않는다.
d[i][0] = max(d[i - 1][0], d[i - 1][1], d[i - 1][2])

2. 마신다. t는 마시는 걸 포함한 연속해서 마신 횟수
d[i][1] = d[i - 1][0] + grape[i]
d[i][2] = d[i - 1][1] + grape[i]

마지막으로 최종해 ans는 max(d[n][0], d[n][1], d[n][2]) 이다.
*/

// bottom-up
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//vector< vector<int> > d(10001, vector<int>(3, -1));
//vector<int> grape(10001, -1);
//
//int main(void) {
//	int n;
//	cin >> n;
//
//	for (int i = 1; i <= n; i++) {
//		cin >> grape[i];
//	}
//
//	// 1. 초기값 설정
//	d[1][0] = 0, d[1][1] = grape[1], d[1][2] = grape[1];
//
//	// 2. dp
//	for (int i = 2; i <= n; i++) {
//		d[i][0] = max(max(d[i - 1][0], d[i - 1][1]), d[i - 1][2]);
//		d[i][1] = d[i - 1][0] + grape[i];
//		d[i][2] = d[i - 1][1] + grape[i];
//	}
//
//	// 3. 최종해 구하기
//	cout << max(max(d[n][0], d[n][1]), d[n][2]);
//
//	return 0;
//}

// 틀림 >> 이유를 모르겠음. 나중에 다시

// top-down
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector< vector<int> > d(10001, vector<int>(4, -1));
vector<int> grape(10001, -1);

int solve(int n, int last) {
	// 3. 초기값 반환
	if (n == 1)return d[n][last];

	// 4. 해가 저장되어 있으면 반환
	if (d[n][last] != -1) return d[n][last];

	// 5. subproblem
	d[n][0] = max(max(solve(n - 1, 0), solve(n - 1, 1)), solve(n - 1, 2));
	d[n][1] = solve(n - 1, 0) + grape[n];
	d[n][2] = solve(n - 1, 1) + grape[n];

	// 6. 최댓값 정하기
	d[n][3] = max(max(d[n][0], d[n][1]), d[n][2]);

	return d[n][last];
}

int main(void) {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> grape[i];
	}

	// 1. 초기값 설정
	d[1][0] = 0;
	d[1][1] = grape[1];
	d[1][2] = grape[1];

	// 2. dp
	cout << solve(n, 3);

	return 0;
}