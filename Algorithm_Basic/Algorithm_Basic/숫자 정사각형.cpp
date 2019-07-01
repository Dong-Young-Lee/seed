#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int n, m;
int rectangle[51][51];

int main(void) {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &rectangle[i][j]);
		}
	}

	int min_value;
	if (n <= m) {
		min_value = n;
	}
	else {
		min_value = m;
	}

	int ans = 1;

	for (int i = 1; i < min_value; i++) {
		for (int j = 0; j < n - i; j++) {
			for (int k = 0; k < m - i; k++) {
				int up_left = rectangle[j][k];
				int up_right = rectangle[j][k + i];
				int down_left = rectangle[j + i][k];
				int down_right = rectangle[j + i][k + i];
				if (up_left == up_right && up_left == down_left && up_left == down_right) {
					int size = (i + 1) * (i + 1);
					if (size > ans) {
						ans = size;
					}
				}
			}
		}
	}

	printf("%d", ans);

	return 0;
}