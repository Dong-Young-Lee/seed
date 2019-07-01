// �ð� �ʰ�
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<bool> check(26, false);
// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
// A B C D E F G H I J K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y  Z

int main(void) {
	int n;
	cin >> n;
	vector<string> words(n);
	for(int i=0; i<n; i++) {
		cin >> words[i];
		int word_size = words[i].size();
		for (int j = 0; j < word_size; j++) {
			check[words[i][j] - 'A'] = true;
		}
	}

	vector<char> used_alphabet;
	for (int i = 0; i < 26; i++) {
		if (check[i]) {
			used_alphabet.push_back(i+'A');
		}
	}

	vector<int> used_numbers;
	int used_alphabet_size = used_alphabet.size();
	int num = 9;
	for (int i = 0; i < used_alphabet_size; i++) {
		used_numbers.push_back(num--);
	}

	sort(used_numbers.begin(), used_numbers.end());

	int ans_max = -1;
	do {
		int temp = 0;
		// i��° string�� ������� ��
		for (int i = 0; i < n; i++) {
			int word_size = words[i].size();

			// i��° string���� j��° ���ڸ� ������� ��
			for (int j = 0; j < word_size; j++) {
				// ���ڿ� �´� ���ڸ� ã��
				for (int k = 0; k < used_alphabet_size; k++) {
					if (words[i][j] == used_alphabet[k]) {
						// ���ڿ� �´� ���ڸ� ã�Ҵٸ�
						// �� ���ڸ� �ڸ��� ��ŭ ���ؼ� temp�� ������
						
						int mul = 1;
						for (int m = word_size - j - 1; m > 0; m--) {
							mul *= 10;
						}
						temp += used_numbers[k] * mul;
					}
				}
			}
		}

		// �ִ� ��
		if (ans_max < temp) {
			ans_max = temp;
		}

	} while (next_permutation(used_numbers.begin(), used_numbers.end()));


	cout << ans_max;

	return 0;
}