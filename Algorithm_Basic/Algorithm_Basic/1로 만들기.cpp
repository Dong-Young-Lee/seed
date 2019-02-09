// top-down
//#include <iostream>
//using namespace std;
//
//int d[1000001] = { 0 };
//
//int make_one(int n) {
//	// 1. 초기값 반환
//	if (n == 1) return 0;
//
//	// 2. 해가 저장되어 있으면 계산하지 않고 반환
//	if (d[n] > 0) return d[n];
//
//	// 해가 저장되어 있지 않으니 해를 구해주고 저장한다
//
//	// 3. 서로 다른 해를 비교하여 최적 해를 저장
//
//	// 해 1
//	d[n] = make_one(n - 1) + 1;
//
//	// 해 2
//	if (n % 3 == 0) {
//		int temp = make_one(n / 3) + 1;
//		if (d[n] > temp) {
//			d[n] = temp;
//		}
//	}
//
//	// 해 3
//	if (n % 2 == 0) {
//		int temp = make_one(n / 2) + 1;
//		if (d[n] > temp) {
//			d[n] = temp;
//		}
//	}
//
//	// 4. 해 반환
//	return d[n];
//}
//
//int main(void) {
//	int n;
//	cin >> n;
//	cout << make_one(n);
//	return 0;
//}



// bottom-up
//#include <iostream>
//using namespace std;
//
//int d[1000001] = { 0 };
//
//int main(void) {
//	int n;
//	cin >> n;
//	// 1. 초기값 반환
//	if (n == 1) cout << 0;
//
//	// 2. bottom-up 이므로 n까지 iteration
//	for (int i = 2; i <= n; i++) {
//
//		// 3. 최적 해를 구하고 저장한다.
//
//		// 해 1
//		d[i] = d[i - 1] + 1;
//
//		// 해 2
//		if (i % 2 == 0) {
//			if (d[i] > d[i / 2] + 1) {
//				d[i] = d[i / 2] + 1;
//			}
//		}
//
//		// 해 3
//		if (i % 3 == 0) {
//			if (d[i] > d[i / 3] + 1) {
//				d[i] = d[i / 3] + 1;
//			}
//		}
//	}
//
//	cout << d[n];
//	return 0;
//}
//
