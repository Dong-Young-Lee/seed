// bottom-up
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> d(100001);
vector<long long> seq(100001);

int main(void) {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> seq[i];
	}

	// 1. 초기값 설정
	for (int i = 1; i <= n; i++) {
		d[i] = seq[i];
	}

	// 2. dp
	for (int i = 2; i <= n; i++) {
		if (d[i - 1] + seq[i] > d[i]) {
			d[i] = d[i - 1] + seq[i];
		}
	}

	// max_element 범위 주위!! 남는 배열을 포함할 수 있음!
	long long ans = *max_element(d.begin()+1, d.begin()+n+1);

	cout << ans;

	return 0;
}