#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	string str;
	cin >> str;

	vector<string> v;
	string temp;

	v.push_back(str);
	for (int i = 1; str[i]; i++) {
		temp = str.substr(i, str.size() - 1);
		v.push_back(temp);
	}

	sort(v.begin(), v.end());

	for (string s : v) {
		cout << s << '\n';
	}

	return 0;

}