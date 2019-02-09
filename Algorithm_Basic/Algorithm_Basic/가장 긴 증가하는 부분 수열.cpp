/*
완전 탐색 문제
dp로 풀 수 있는가?
yes, 왜냐하면 problem의 답을 찾을 때 subproblem의 답이 일정하므로 가능
그 일정한 답을 기억하면 되기 때문이다.

d[n] 정의
n번 째 수까지 부분수열의 최대 길이

< d[n] 구하는 방법 >
seq[n] : 수열의 n번째 수

d[1] = 1

수열 seq에서 각 수에서 그 수를 포함한 가장 긴 부분 수열을 저장한다.
그러기 위해서 d[n]을 구할 때, seq[n-1]부터 seq[1]까지 진행하며
seq[n]보다 작은지 확인한다.
만약에 작다면 d[n] = d[n-m] + 1 을 하여 구해준다.

최종해는 max(d) 이다.
*/

// bottom-up
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//vector<int> d(1001, -1);
//vector<int> seq(1001, -1);
//
//int main(void) {
//	int n;
//	cin >> n;
//
//	for (int i = 1; i <= n; i++) {
//		cin >> seq[i];
//	}
//
//	// 1. 초기값 설정
//	d[1] = 1;
//
//	// 2. dq
//	for (int i = 1; i <= n; i++) {
//		d[i] = 1;
//		for (int j = 1; j < i; j++) {
//			if (seq[i] > seq[j] && d[i] <= d[j]) {
//				d[i] = d[j] + 1;
//			}
//		}
//	}
//
//	// 3. 구한 해 중에 최대값을 찾는다.
//	cout << *max_element(d.begin(), d.end());
//	
//	return 0;
//}

// 실패, 다시 시도

// top-down
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//vector<int> d(1001, -1);
//vector<int> seq(1001, -1);
//
//int solve(int n) {
//	// 2. 초기값 반환
//	if (n == 1)return d[1];
//
//	// 3. 해가 저장되어 있으면 반환
//	if (d[n] != -1) return d[n];
//
//	// 4. subproblem
//	for (int i = 1; i < n; i++) {
//
//		if (seq[n] > seq[i] && d[n] < solve(i) + 1) {
//			d[n] = solve(i) + 1;
//		}
//	}
//
//	return d[n];
//}
//
//int main(void) {
//	int n;
//	cin >> n;
//
//	for (int i = 1; i <= n; i++) {
//		cin >> seq[i];
//	}
//
//	// 1. 초기값 설정
//	d[1] = 1;
//
//	// dp
//	solve(n);
//
//	int ans = *max_element(d.begin(), d.end());
//
//	cout << ans;
//
//	return 0;
//}