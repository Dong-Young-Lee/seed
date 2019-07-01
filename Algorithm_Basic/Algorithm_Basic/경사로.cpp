#include <iostream>
#include <vector>
using namespace std;

int n, l;
int main(void) {
	cin >> n >> l;
	vector< vector<int> > map(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	int ans = 0;
	// 행 기준
	for (int i = 0; i < n; i++) {
		vector<bool> slope(n, false);
		for (int j = 0; j < n - 1; j++) {
			// 현재 칸과 다음 칸의 높이가 같음
			if (map[i][j] == map[i][j + 1]) {
				if (j + 1 == n - 1) { // 마지막 칸
					ans += 1;
				}
			}
			else if (map[i][j] - map[i][j + 1] == 1) { // 내리막
				if (j + l <= n - 1) { // 경사로를 놓을 수 있는 범위
					bool ok = true;
					for (int k = 2; k <= l; k++) {
						if (map[i][j + k] != map[i][j] - 1) {
							ok = false;
							break;
						}
					}
					if (ok) { // 경사로를 놓음
						for (int k = j + 1; k <= j + l; k++) {
							slope[k] = true;
						}
						j += l - 1;
						if (j + 1 == n - 1) {
							ans += 1;
							break;
						}
					}
					else { // 경사로를 놓지 못함
						break;
					}
				}
				else { // 경사로를 놓으면 지도에서 벗어남
					break;
				}
			}
			else if (map[i][j] - map[i][j + 1] == -1) { // 오르막
				if (j - l >= -1) { // 경사로를 놓을 수 있는 범위
					bool ok = true;
					for (int k = 2; k <= l; k++) {
						if (map[i][j - k + 1] != map[i][j]) {
							ok = false;
							break;
						}
					}
					if (ok) { // 경사로를 놓음
						bool overlap = false;
						for (int k = j; k > j - l; k--) {
							if (slope[k]) {
								overlap = true;
								break;
							}
						}
						if (overlap) { // 경사로를 놓을 위치에 이미 존재
							break;
						}
						else {
							for (int k = j; k > j - l; k--) {
								slope[k] = true;
							}
							if (j + 1 == n - 1) {
								ans += 1;
								break;
							}
						}
					}
					else { // 경사로를 놓지 못함
						break;
					}
				}
				else { // 경사로를 놓으면 지도에서 벗어남
					break;
				}
			}
			else { // 불가능
				break;
			}
		}
	}


	// 열 기준
	for (int j = 0; j < n; j++) {
		vector<bool> slope(n, false);
		for (int i = 0; i < n - 1; i++) {
			// 현재 칸과 다음 칸의 높이가 같음
			if (map[i][j] == map[i + 1][j]) {
				if (i + 1 == n - 1) { // 마지막 칸
					ans += 1;
				}
			}
			else if (map[i][j] - map[i + 1][j] == 1) { // 내리막
				if (i + l <= n - 1) { // 경사로를 놓을 수 있는 범위
					bool ok = true;
					for (int k = 2; k <= l; k++) {
						if (map[i + k][j] != map[i][j] - 1) {
							ok = false;
							break;
						}
					}
					if (ok) { // 경사로를 놓음
						for (int k = i + 1; k <= i + l; k++) {
							slope[k] = true;
						}
						i += l - 1;
						if (i + 1 == n - 1) {
							ans += 1;
							break;
						}
					}
					else { // 경사로를 놓지 못함
						break;
					}
				}
				else { // 경사로를 놓으면 지도에서 벗어남
					break;
				}
			}
			else if (map[i][j] - map[i + 1][j] == -1) { // 오르막
				if (i - l >= -1) { // 경사로를 놓을 수 있는 범위
					bool ok = true;
					for (int k = 2; k <= l; k++) {
						if (map[i - k + 1][j] != map[i][j]) {
							ok = false;
							break;
						}
					}
					if (ok) { // 경사로를 놓음
						bool overlap = false;
						for (int k = i; k > i - l; k--) {
							if (slope[k]) {
								overlap = true;
								break;
							}
						}
						if (overlap) { // 경사로를 놓을 위치에 이미 존재
							break;
						}
						else {
							for (int k = i; k > i - l; k--) {
								slope[k] = true;
							}
							if (i + 1 == n - 1) {
								ans += 1;
								break;
							}
						}
					}
					else { // 경사로를 놓지 못함
						break;
					}
				}
				else { // 경사로를 놓으면 지도에서 벗어남
					break;
				}
			}
			else { // 불가능
				break;
			}
		}
	}

	cout << ans;
	return 0;
}