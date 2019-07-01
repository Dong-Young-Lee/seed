#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int l, c;
vector<char> alphabet;

int isused[15];
char str[16];
int used_numbers;

void func() {
	if (used_numbers == l) {
		int mo = 0, ja = 0;
		
		for (int i = 1; i <= l; i++) {
			if (str[i] == 'a' ||
				str[i] == 'e' ||
				str[i] == 'i' ||
				str[i] == 'o' ||
				str[i] == 'u') {
				mo++;
			}
			else {
				ja++;
			}
		}
		
		if (mo >= 1 && ja >= 2) {
			for (int i = 1; i <= l; i++) {
				cout << str[i];
			}
			cout << '\n';
		}
	}

	for (int i = 0; i < c; i++) {
		if (isused[i] == 0) {
			if (alphabet[i] >= str[used_numbers]) {
				isused[i] = 1;
				str[used_numbers + 1] = alphabet[i];
				used_numbers++;
				func();
				isused[i] = 0;
				used_numbers--;
			}
		}
	}
}

int main(void) {
	str[0] = 'a';
	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		char temp;
		cin >> temp;
		alphabet.push_back(temp);
	}
	sort(alphabet.begin(), alphabet.end());

	func();
	return 0;
}