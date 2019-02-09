// top-down
//#include <iostream>
//using namespace std;
//
//int d[1000001] = { 0 };
//
//int make_one(int n) {
//	// 1. �ʱⰪ ��ȯ
//	if (n == 1) return 0;
//
//	// 2. �ذ� ����Ǿ� ������ ������� �ʰ� ��ȯ
//	if (d[n] > 0) return d[n];
//
//	// �ذ� ����Ǿ� ���� ������ �ظ� �����ְ� �����Ѵ�
//
//	// 3. ���� �ٸ� �ظ� ���Ͽ� ���� �ظ� ����
//
//	// �� 1
//	d[n] = make_one(n - 1) + 1;
//
//	// �� 2
//	if (n % 3 == 0) {
//		int temp = make_one(n / 3) + 1;
//		if (d[n] > temp) {
//			d[n] = temp;
//		}
//	}
//
//	// �� 3
//	if (n % 2 == 0) {
//		int temp = make_one(n / 2) + 1;
//		if (d[n] > temp) {
//			d[n] = temp;
//		}
//	}
//
//	// 4. �� ��ȯ
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
//	// 1. �ʱⰪ ��ȯ
//	if (n == 1) cout << 0;
//
//	// 2. bottom-up �̹Ƿ� n���� iteration
//	for (int i = 2; i <= n; i++) {
//
//		// 3. ���� �ظ� ���ϰ� �����Ѵ�.
//
//		// �� 1
//		d[i] = d[i - 1] + 1;
//
//		// �� 2
//		if (i % 2 == 0) {
//			if (d[i] > d[i / 2] + 1) {
//				d[i] = d[i / 2] + 1;
//			}
//		}
//
//		// �� 3
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
