#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string str;
	while (getline(cin, str)) {
		int result[4] = { 0 };
		for (int i = 0; str[i]; i++) {
			if (str[i] >= 'a' && str[i] <= 'z') {
				result[0] += 1;
			}
			else if (str[i] >= 'A' && str[i] <= 'Z') {
				result[1] += 1;
			}
			else if (str[i] >= '0' && str[i] <= '9') {
				result[2] += 1;
			}
			else if (str[i] == ' ') {
				result[3] += 1;
			}
		}
		for (int i = 0; i < 4; i++) {
			cout << result[i] << " ";
		}
		cout << '\n';
	}
	return 0;
}