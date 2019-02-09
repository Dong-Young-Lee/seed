/*
d[n]은 n을 제곱수들의 합으로 표현할 수 있는 항의 최소 개수
마지막 항에 집중한다.

*/



#include <iostream>
#include <vector>
using namespace std;

// 초기화 조심!!
vector<int> d(100001, 0);

int main(void) {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		// 제일 큰 항의 개수는 모두 1로 이루어 진 것
		d[i] = i;
		for (int j = 1; (j*j) <= i; j++) {
			// 최소 항의 개수 찾기
			if (d[i] > d[i - (j * j)] + 1) {
				d[i] = d[i - (j * j)] + 1;
			}
		}
	}

	cout << d[n];

	return 0;
}