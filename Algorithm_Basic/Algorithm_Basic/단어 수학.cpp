// 시간 초과
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
		// i번째 string을 대상으로 함
		for (int i = 0; i < n; i++) {
			int word_size = words[i].size();

			// i번째 string에서 j번째 글자를 대상으로 함
			for (int j = 0; j < word_size; j++) {
				// 글자에 맞는 숫자를 찾음
				for (int k = 0; k < used_alphabet_size; k++) {
					if (words[i][j] == used_alphabet[k]) {
						// 글자에 맞는 숫자를 찾았다면
						// 그 숫자를 자릿수 만큼 곱해서 temp에 더해줌
						
						int mul = 1;
						for (int m = word_size - j - 1; m > 0; m--) {
							mul *= 10;
						}
						temp += used_numbers[k] * mul;
					}
				}
			}
		}

		// 최댓값 비교
		if (ans_max < temp) {
			ans_max = temp;
		}

	} while (next_permutation(used_numbers.begin(), used_numbers.end()));


	cout << ans_max;

	return 0;
}