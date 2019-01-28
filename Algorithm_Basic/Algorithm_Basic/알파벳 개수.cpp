#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;
	int size = str.size();

	int num_of_apb[26] = { 0 };
	for (int i = 0; i < size; i++) {
		for (char apb = 'a'; apb <= 'z'; apb++) {
			if (str[i] == apb) {
				num_of_apb[apb - 97] += 1;
			}
		}
	}

	for (int i = 0; i < 26; i++) {
		printf("%d ", num_of_apb[i]);
	}

	return 0;

}