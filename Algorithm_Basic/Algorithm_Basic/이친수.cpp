// 유사문제 : 포도주 시식

/*
n자리 이친수의 개수를 구할 때, n-1자리 이친수의 개수를 이용한다.
따라서, 마지막 자리에 집중한다.

n자리 이친수의 개수를 구할 때, n-1자리 이친수의 마지막 자리와 이 다음에 올 수를 비교한다.
그러므로 d는 다음과 같이 정의한다.

d[n][last] : 마지막 자리가 last인 n자리 이친수의 개수
last의 범위는 ( 0 <= last <= 2 )이며, 
last가 2일 때, d[n][2]는 n자리 이친수의 개수이다.
따라서 d[n][2] = d[n][0] + d[n][1]이다.

last 2일 때를 구하기 위한 subproblem을 푸는 방법은 다음과 같다.

d[n][0] = d[n-1][0] + d[n-1][1]
d[n][1] = d[n-1][0]

<예외 1> : 이친수는 0으로 시작하지 않는다.
>> d[1][0] = 0
d[1][1] = 1
d[1][2] = 1
*/

// bottom-up
//#include <iostream>
//#include <vector>
//using namespace std;
//
//vector< vector<long long> > d(91, vector<long long>(3, -1));
//
//int main(void) {
//	int n;
//	cin >> n;
//
//	// 1. 초기값 설정
//	d[1][0] = 0, d[1][1] = 1, d[1][2] = 1;
//
//	// 2. subproblem
//	for (int i = 2; i <= n; i++) {
//		d[i][0] = d[i - 1][0] + d[i - 1][1];
//		d[i][1] = d[i - 1][0];
//		d[i][2] = d[i][0] + d[i][1];
//	}
//
//	// 3. problem
//	cout << d[n][2];
//	return 0;
//}

// top-down
#include <iostream>
#include <vector>
using namespace std;

vector< vector<long long> > d(91, vector<long long>(3, -1));

long long solve(int n, int last) {
	// 2. 초기값 반환
	if (n == 1) return d[n][last];

	// 3. 해가 저장되어 있으면 반환
	if (d[n][last] != -1) return d[n][last];

	// 4. subproblem
	d[n][0] = solve(n - 1, 0) + solve(n - 1, 1);
	d[n][1] = solve(n - 1, 0);

	// 5. problem
	d[n][2] = d[n][0] + d[n][1];

	return d[n][last];
}

int main(void) {
	int n;
	cin >> n;

	// 1. 초기값 설정
	d[1][0] = 0, d[1][1] = 1, d[1][2] = 1;

	cout << solve(n, 2);
	return 0;
}