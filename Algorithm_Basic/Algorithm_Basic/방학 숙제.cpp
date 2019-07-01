#include <iostream>
using namespace std;

int main(void) {
	int l, a, b, c, d;
	cin >> l >> a >> b >> c >> d;
	
	int kor = 0;
	int quotient = a / c;
	int remainder = a % c;
	if (remainder == 0) {
		kor = quotient;
	}
	else {
		kor = quotient + 1;
	}

	int math = 0;
	quotient = b / d;
	remainder = b % d;
	if (remainder == 0) {
		math = quotient;
	}
	else {
		math = quotient + 1;
	}

	int cnt;
	if (kor > math) {
		cnt = kor;
	}
	else {
		cnt = math;
	}

	cout << l - cnt;

	return 0;
}