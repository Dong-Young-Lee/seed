// bottom-up
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// d[n]은 seq에서 n번째 수를 포함한 
// 증가 부분 수열중에서 합이 가장 큰 값
vector<int> d(1001, -1);
vector<int> seq(1001);

int main(void) {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> seq[i];
	}

	// 1. 초기값 저장
	for (int i = 1; i <= n; i++) {
		d[i] = seq[i];
	}

	// 2. dp
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (seq[i] > seq[j]) {
				if (d[j] + seq[i] > d[i]) {
					d[i] = d[j] + seq[i];
				}
			}
		}
	}

	cout << *max_element(d.begin(), d.end());

	return 0;
}