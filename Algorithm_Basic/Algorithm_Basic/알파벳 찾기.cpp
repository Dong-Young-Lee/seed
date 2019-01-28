#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string str;
	cin >> str;

	int first_apb[26];
	fill_n(first_apb, 26, -1);
	int find[26] = { 0 };

	for (int i = 0; str[i]; i++) {
		for (int j = 0; j < 26; j++) {
			if (str[i] == 'a' + j) {
				if (find[j] == 0) {
					first_apb[j] = i;
					find[j] = 1;
				}
			}
		}
	}

	for (int i = 0; i < 26; i++) {
		printf("%d ", first_apb[i]);
	}

	return 0;
}