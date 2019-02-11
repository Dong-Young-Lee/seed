/*
< Brute Force >
n중 for문

< Time Complexity >
9명 중에서 2명을 제외하는 경우의 수
n_C_2 : n(n-1) / 2 따라서 O(n^2)

7명의 키를 더하는 시간 O(n)

결과적으로 O(n^3)
*/

// O(n^2)으로 풀 수 있다. 소스 코드 참조

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> input(9);
vector<int> check(9,0);

int main(void) {
	for (int i = 0; i < 9; i++) {
		cin >> input[i];
	}

	sort(input.begin(), input.end());

	int flag = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (i == j) {
				continue;
			}
			check[i] = 1;
			check[j] = 1;
			int sum = 0;
			for (int k = 0; k < 9; k++) {
				if (check[k] != 1) {
					sum += input[k];
				}
			}
			if (sum == 100) {
				flag = 1;
				break;
			}
			else {
				for (int k = 0; k < 9; k++) {
					check[k] = 0;
				}
			}
		}
		if (flag == 1) {
			break;
		}
	}

	for (int i = 0; i < 9; i++) {
		if (check[i] != 1) {
			cout << input[i] << '\n';
		}
	}

	return 0;
}