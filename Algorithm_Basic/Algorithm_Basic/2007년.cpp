#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <string>

int days_in_each_month[12] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 };

std::string days_of_week[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };

int main(void) {
	std::ios_base::sync_with_stdio(false);
	int x, y;
	scanf("%d %d", &x, &y);
	
	int total_days = 0;
	for (int i = 0; i < x; i++) {
		total_days += days_in_each_month[i];
	}
	total_days += y;
	
	total_days %= 7;

	std::cout << days_of_week[total_days];

	return 0;

}