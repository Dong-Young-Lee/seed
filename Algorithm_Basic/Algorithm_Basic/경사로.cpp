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
	// �� ����
	for (int i = 0; i < n; i++) {
		vector<bool> slope(n, false);
		for (int j = 0; j < n - 1; j++) {
			// ���� ĭ�� ���� ĭ�� ���̰� ����
			if (map[i][j] == map[i][j + 1]) {
				if (j + 1 == n - 1) { // ������ ĭ
					ans += 1;
				}
			}
			else if (map[i][j] - map[i][j + 1] == 1) { // ������
				if (j + l <= n - 1) { // ���θ� ���� �� �ִ� ����
					bool ok = true;
					for (int k = 2; k <= l; k++) {
						if (map[i][j + k] != map[i][j] - 1) {
							ok = false;
							break;
						}
					}
					if (ok) { // ���θ� ����
						for (int k = j + 1; k <= j + l; k++) {
							slope[k] = true;
						}
						j += l - 1;
						if (j + 1 == n - 1) {
							ans += 1;
							break;
						}
					}
					else { // ���θ� ���� ����
						break;
					}
				}
				else { // ���θ� ������ �������� ���
					break;
				}
			}
			else if (map[i][j] - map[i][j + 1] == -1) { // ������
				if (j - l >= -1) { // ���θ� ���� �� �ִ� ����
					bool ok = true;
					for (int k = 2; k <= l; k++) {
						if (map[i][j - k + 1] != map[i][j]) {
							ok = false;
							break;
						}
					}
					if (ok) { // ���θ� ����
						bool overlap = false;
						for (int k = j; k > j - l; k--) {
							if (slope[k]) {
								overlap = true;
								break;
							}
						}
						if (overlap) { // ���θ� ���� ��ġ�� �̹� ����
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
					else { // ���θ� ���� ����
						break;
					}
				}
				else { // ���θ� ������ �������� ���
					break;
				}
			}
			else { // �Ұ���
				break;
			}
		}
	}


	// �� ����
	for (int j = 0; j < n; j++) {
		vector<bool> slope(n, false);
		for (int i = 0; i < n - 1; i++) {
			// ���� ĭ�� ���� ĭ�� ���̰� ����
			if (map[i][j] == map[i + 1][j]) {
				if (i + 1 == n - 1) { // ������ ĭ
					ans += 1;
				}
			}
			else if (map[i][j] - map[i + 1][j] == 1) { // ������
				if (i + l <= n - 1) { // ���θ� ���� �� �ִ� ����
					bool ok = true;
					for (int k = 2; k <= l; k++) {
						if (map[i + k][j] != map[i][j] - 1) {
							ok = false;
							break;
						}
					}
					if (ok) { // ���θ� ����
						for (int k = i + 1; k <= i + l; k++) {
							slope[k] = true;
						}
						i += l - 1;
						if (i + 1 == n - 1) {
							ans += 1;
							break;
						}
					}
					else { // ���θ� ���� ����
						break;
					}
				}
				else { // ���θ� ������ �������� ���
					break;
				}
			}
			else if (map[i][j] - map[i + 1][j] == -1) { // ������
				if (i - l >= -1) { // ���θ� ���� �� �ִ� ����
					bool ok = true;
					for (int k = 2; k <= l; k++) {
						if (map[i - k + 1][j] != map[i][j]) {
							ok = false;
							break;
						}
					}
					if (ok) { // ���θ� ����
						bool overlap = false;
						for (int k = i; k > i - l; k--) {
							if (slope[k]) {
								overlap = true;
								break;
							}
						}
						if (overlap) { // ���θ� ���� ��ġ�� �̹� ����
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
					else { // ���θ� ���� ����
						break;
					}
				}
				else { // ���θ� ������ �������� ���
					break;
				}
			}
			else { // �Ұ���
				break;
			}
		}
	}

	cout << ans;
	return 0;
}