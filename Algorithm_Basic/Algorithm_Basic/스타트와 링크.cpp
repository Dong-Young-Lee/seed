#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

bool present_item(vector<int> &vec, int item) {
	if (find(vec.begin(), vec.end(), item) != vec.end()) {
		return true;
	}
	else {
		return false;
	}
}

int main(void) {
	int n;
	cin >> n;
	vector< vector<int> > input(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> input[i][j];
		}
	}

	vector<int> seq(n / 2);
	for (int i = 0; i < n / 2; i++) {
		seq.push_back(1);
	}

	int ans_min = numeric_limits<int>::max();

	// n�� �߿��� 2/n���� �̴´�.
	// ��� ����� ���� Ȯ��
	do {
		vector<int> start; // 1
		vector<int> link; // 0
		for (int i = 0; i < n; i++) {
			if (seq[i]) {
				start.push_back(i);
			}
			else {
				link.push_back(i);
			}
		}

		// �� ���� �ɷ�ġ�� ����
		int start_score = 0;
		int link_score = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (present_item(start, i) && present_item(start, j)) {
					start_score += input[i][j];
				}
				if (present_item(link, i) && present_item(link, j)) {
					link_score += input[i][j];
				}

			}
		}

		// �ɷ�ġ�� ����
		int cmp_ans = start_score - link_score;
		if (cmp_ans < 0) cmp_ans *= -1;

		if (ans_min > cmp_ans) {
			ans_min = cmp_ans;
		}

	} while (next_permutation(seq.begin(), seq.end()));
	
	cout << ans_min << '\n';

	return 0;
}