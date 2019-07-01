#include <iostream>
#include <vector>
using namespace std;

int d_r[4] = { -1, -2, 1, 2 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	while (t <= 10) {
		int n;
		cin >> n;
		vector< vector<int> > map(n, vector<int>(255, 0));
		for (int i = 0; i < n; i++) {
			int height;
			cin >> height;
			for (int j = 0; j < height; j++) {
				map[i][j] = 1;
			}
		}

		int cnt = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 255; j++) {
				if (map[i][j] == 1) {
					bool ok = true;
					for (int k = 0; k < 4; k++) {
						int next = i + d_r[k];
						if (next >= 0 && next < n) {
							if (map[next][j] != 0) {
								ok = false;
								break;
							}
						}
					}
					if (ok) {
						cnt++;
					}
				}
			}
		}

		cout << '#' << t << ' ' << cnt << '\n';
		t++;
	}

	return 0;
}