#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string str;
	getline(cin, str);

	for (int i = 0; str[i]; i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			if (str[i] + 13 > 'z') {
				str[i] = 'a' + str[i] + 12 - 'z';
			}
			else {
				str[i] += 13;
			}
		}
		else if(str[i] >= 'A' && str[i] <= 'Z') {
			if (str[i] + 13 > 'Z') {
				str[i] = 'A' + str[i] + 12 - 'Z';
			}
			else {
				str[i] += 13;
			}
		}
	}
	cout << str;
	return 0;
}