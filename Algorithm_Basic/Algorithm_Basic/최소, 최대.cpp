#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n;
	//scanf("%d", &n);
	std::cin >> n;

	int min = 1000000;
	int max = -1000000;
	int next;
	for(int i=0; i<n; i++){
		//scanf("%d", &next);
		std::cin >> next;
		if (min > next) {
			min = next;
		}
		if (max < next) {
			max = next;
		}
	}
	//printf("%d %d", min, max);
	std::cout << min << " " << max;

	return 0;
}