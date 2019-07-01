#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

const int MAX = 50;
int n;
char map[MAX][5][7];

int main(void) {
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		for (int r = 0; r < 5; r++) {
			for (int c = 0; c < 7; c++) {
				scanf("%c\n", &map[i][r][c]);
			}
		}
	}

	int ans = 2147483647;
	int a = -1;
	int b = -1;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			int cnt = 0;
			for (int r = 0; r < 5; r++) {
				for (int c = 0; c < 7; c++) {
					if (map[i][r][c] != map[j][r][c]) {
						cnt++;
					}
				}
			}
			if (ans > cnt) {
				ans = cnt;
				a = i + 1;
				b = j + 1;
			}
		}
	}

	printf("%d %d", a, b);

	return 0;
}