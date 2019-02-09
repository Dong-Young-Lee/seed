/*
d[n] 정의 : 정수 n을 1, 2, 3의 합으로 나타내는 방법의 수

d[n]을 구하는 방법
<조건 1> 같은 수를 두 번 이상 연속해서 사용하면 안됨.

일단 <조건 1>을 제외하면, d[n]을 구하는 방법은
마지막에 더하는 숫자에 주목한다.
마지막에 더하는 숫자는 1, 2, 3 세 개중 하나가 올 수 있다.
1이 오는 경우, 정수 n은 n-1에서 1을 더한 것이다.
2가 오는 경우, 정수 n은 n-2에서 2를 더한 것이다.
3이 오는 경우, 정수 n은 n-3에서 3을 더한 것이다.

위 세 가지 경우의 수를 모두 더하면 d[n]을 구할 수 있다.

그렇다면 각 경우의 수는 어떻게 구할까?
d[n-1], d[n-2], d[n-3]을 구했다면 쉽게 알 수 있다.

따라서, d[n] = d[n-1] + d[n-2] + d[n-3] 이다.

여기서 <조건 1>을 고려하면서 마지막에 더하는 숫자를 기준으로 한다면,
이 전에 구한 더하는 방법에서 마지막에 더한 숫자를 알아야 한다.
그리고 이와 비교하여 같을 경우에는 더하지 않는다.
따라서 마지막 숫자를 알아야 하기 때문에 d는 2차원 배열로 선언한다.

d[n][1] : 정수 n을 1, 2, 3의 합으로 나타내며 1로 끝나는 방법의 수
>> d[n][1] = d[n-1][2] + d[n-1][3]

d[n][2] : 정수 n을 1, 2, 3의 합으로 나타내며 2로 끝나는 방법의 수
>> d[n][2] = d[n-2][1] + d[n-2][3]

d[n][3] : 정수 n을 1, 2, 3의 합으로 나타내며 3으로 끝나는 방법의 수
>> d[n][3] = d[n-3][1] + d[n-3][2]

따라서, 정수 n을 1, 2, 3의 합으로 나타내는 방법의 수를 이렇게 정의한다.
d[n][0] = d[n][1] + d[n][2] + d[n][3]
*/

// bottom-up
//#include <iostream>
//#include <vector>
//using namespace std;
//
//vector< vector<long long> > d(100001, vector<long long>(4, -1));
//const long long mod = 1000000009LL;
//
//int main(void) {
//	int t;
//	cin >> t;
//
//	// 1. 초기값 설정
//	d[1][1] = 1, d[1][2] = 0, d[1][3] = 0, d[1][0] = 1;
//	d[2][1] = 0, d[2][2] = 1, d[2][3] = 0, d[2][0] = 1;
//	d[3][1] = 1, d[3][2] = 1, d[3][3] = 1, d[3][0] = 3;
//
//	while (t--) {
//		int n;
//		cin >> n;
//
//		// 2. 해가 저장되어 있으면 출력
//		if (d[n][0] != -1) {
//			std::cout << d[n][0] << '\n';
//			continue;
//		}
//
//		// 3. subproblem을 풀며 저장하기
//		for (int i = 4; i <= n; i++) {
//			d[i][1] = (d[i - 1][2] + d[i - 1][3]) % mod;
//			d[i][2] = (d[i - 2][1] + d[i - 2][3]) % mod;
//			d[i][3] = (d[i - 3][1] + d[i - 3][2]) % mod;
//			
//			// 4. subproblem으로 problem 풀고 저장
//			d[i][0] = (d[i][1] + d[i][2] + d[i][3]) % mod;
//		}
//
//		cout << d[n][0] << '\n';
//
//	}
//	return 0;
//}

// top-down
#include <iostream>
#include <vector>
using namespace std;

vector< vector<long long> > d(100001, vector<long long>(4, -1));
const long long mod = 1000000009LL;

long long solve(int n, int last) {
	// 2. 초기값 반환
	if (n <= 3) return d[n][last];

	// 3. 해가 저장되어 있으면 바로 반환
	if (d[n][last] != -1) {
		return d[n][last];
	}

	// 4. subproblem을 구하고 저장
	d[n][1] = (solve(n - 1, 2) + solve(n - 1, 3)) % mod;
	d[n][2] = (solve(n - 2, 1) + solve(n - 2, 3)) % mod;
	d[n][3] = (solve(n - 3, 1) + solve(n - 3, 2)) % mod;

	// 5. subproblem을 이용하여 problem을 풀고 저장
	d[n][0] = (d[n][1] + d[n][2] + d[n][3]) % mod;

	// 6. 반환
	return d[n][last];

}

int main(void) {
	int t;
	cin >> t;

	// 1. 초기값 저장
	d[1][1] = 1, d[1][2] = 0, d[1][3] = 0, d[1][0] = 1;
	d[2][1] = 0, d[2][2] = 1, d[2][3] = 0, d[2][0] = 1;
	d[3][1] = 1, d[3][2] = 1, d[3][3] = 1, d[3][0] = 3;

	while (t--) {
		int n;
		cin >> n;
		cout << solve(n, 0) << '\n';
	}
	return 0;
}