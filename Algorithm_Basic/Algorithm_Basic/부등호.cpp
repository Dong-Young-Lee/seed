// ½ÇÆÐ
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	int t = n;
	vector<char> ineq;
	while (t--) {
		char c;
		cin >> c;
		ineq.push_back(c);
	}

	vector<int> perm_mask(9-n, 0);
	for (int i = 0; i < n+1; i++) {
		perm_mask.push_back(1);
	}

	int ans_max = -1;
	vector<int> ans_max_vec(n + 1);
	int ans_min = numeric_limits<int>::max();
	vector<int> ans_min_vec(n + 1);

	do {
		vector<int> selected_numbers;
		for (int i = 0; i < 10; i++) {
			if (perm_mask[i]) {
				selected_numbers.push_back(i);
			}
		}

		sort(selected_numbers.begin(), selected_numbers.end());
		do {
			int ineq_size = ineq.size();
			int satisfy = 1;
			for (int i = 0; i < ineq_size; i++) {
				if (ineq[i] == '>') {
					if (selected_numbers[i] < selected_numbers[i + 1]) {
						satisfy = 0;
						break;
					}
				}
				else {
					if (selected_numbers[i] > selected_numbers[i + 1]) {
						satisfy = 0;
						break;
					}
				}
			}
			if (satisfy) {
				int sat_num = 0;
				int sel_size = selected_numbers.size();

				for (int i = 0; i < sel_size; i++) {
					int temp = 1;
					for (int j = 0; j < sel_size - i - 1; j++) {
						temp *= 10;
					}
					sat_num += selected_numbers[i] * temp;
				}

				if (ans_max < sat_num) {
					ans_max = sat_num;
					for (int i = 0; i < n + 1; i++) {
						ans_max_vec[i] = selected_numbers[i];
					}
				}

				if (ans_min > sat_num) {
					ans_min = sat_num;
					for (int i = 0; i < n + 1; i++) {
						ans_min_vec[i] = selected_numbers[i];
					}
				}

			}
		} while (next_permutation(selected_numbers.begin(), selected_numbers.end()));

	} while (next_permutation(perm_mask.begin(), perm_mask.end()));

	for (int i = 0; i < n + 1; i++) {
		cout << ans_max_vec[i];
	}
	cout << '\n';
	for (int i = 0; i < n + 1; i++) {
		cout << ans_min_vec[i];
	}
	cout << '\n';

	return 0;
}