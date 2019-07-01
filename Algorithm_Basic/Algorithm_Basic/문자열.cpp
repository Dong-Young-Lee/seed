#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string s1;
	string s2;

	cin >> s1 >> s2;

	int diff = s2.size() - s1.size();

	int ans = 100;
	for (int i = 0; i <= diff; i++) {
		int cnt = 0;
		int s1_size = s1.size();
		for (int j = 0; j < s1_size; j++) {
			if (s1[j] != s2[j+i]) {
				cnt++;
			}
		}
		if (ans > cnt) {
			ans = cnt;
		}
	}
	cout << ans;

	return 0;
}