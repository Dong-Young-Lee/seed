#include <iostream>
#include <string>
using namespace std;

int main(void) {
	unsigned long long a, b, c, d;
	cin >> a >> b >> c >> d;

	string a_s = to_string(a);
	string b_s = to_string(b);
	string c_s = to_string(c);
	string d_s = to_string(d);

	string apb_s = a_s + b_s;
	string cpd_s = c_s + d_s;

	unsigned long long apb = stoull(apb_s);
	unsigned long long cpd = stoull(cpd_s);

	cout << apb + cpd;

	return 0;
}