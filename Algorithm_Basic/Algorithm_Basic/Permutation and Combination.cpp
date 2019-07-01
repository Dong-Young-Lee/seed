// 중복 순열 ( Permutation with repetition )

//#include <iostream>
//using namespace std;
//
//const int N = 5;
//const int R = 3;
//
//int numbers[N];
//int used_numbers;
//
//int cnt;
//
//void find_permutation() {
//	if (used_numbers == R) {
//		for (int i = 0; i < used_numbers; i++) {
//			cout << numbers[i] << ' ';
//		}
//		cout << '\n';
//		cnt++;
//		return;
//	}
//	for (int i = 0; i < N; i++) {
//		numbers[used_numbers] = i;
//		used_numbers++;
//		find_permutation();
//		used_numbers--;
//	}
//}
//
//int main(void) {
//	find_permutation();
//	cout << "cnt : " << cnt << '\n';
//	return 0;
//}


// 순열 ( Permutation )

//#include <iostream>
//using namespace std;
//
//const int N = 5;
//const int R = 3;
//
//int is_used[N];
//int numbers[N];
//int used_numbers;
//
//int cnt;
//
//void find_permutation() {
//	if (used_numbers == R) {
//		for (int i = 0; i < used_numbers; i++) {
//			cout << numbers[i] << ' ';
//		}
//		cout << '\n';
//		cnt++;
//		return;
//	}
//	for (int i = 0; i < N; i++) {
//		if (is_used[i] == 0) {
//			is_used[i] = 1;
//			numbers[used_numbers] = i;
//			used_numbers++;
//			find_permutation();
//			is_used[i] = 0;
//			used_numbers--;
//		}
//	}
//}
//
//int main(void) {
//	find_permutation();
//	cout << "cnt : " << cnt << '\n';
//	return 0;
//}