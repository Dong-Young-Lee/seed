#include <iostream>
#include <vector>
using namespace std;

int a, b, c;
vector<int> parkinglot(101);

int main(void) {
	cin >> a >> b >> c;

	for (int i = 0; i < 3; i++) {
		int fir, sec;
		cin >> fir >> sec;
		for (int i = fir; i < sec; i++) {
			parkinglot[i]++;
		}
	}

	int ans = 0;
	for (int i = 1; i < 101; i++) {
		if (parkinglot[i] == 1) {
			ans += a;
		}
		else if (parkinglot[i] == 2) {
			ans += b * 2;
		}
		else if (parkinglot[i] == 3) {
			ans += c * 3;
		}
	}
	
	cout << ans;

	return 0;
}