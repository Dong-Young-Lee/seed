#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 15;

int l, c;
char characters[15];

void solve(int index, int len, string str) {
	if (index > c || len > l) return;
	if (len == l) {
		int ja = 0;
		int mo = 0;
		for (int i = 0; i < l; i++) {
			if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' ||
				str[i] == 'o' || str[i] == 'u') {
				mo++;
			}
			else {
				ja++;
			}
		}
		if (ja >= 2 && mo >= 1) {
			cout << str << '\n';
		}
		return;
	}

	solve(index + 1, len + 1, str + characters[index]);
	solve(index + 1, len, str);
}

int main(void) {
	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		cin >> characters[i];
	}
	sort(characters, characters + c);

	solve(0, 0,"");

	return 0;
}