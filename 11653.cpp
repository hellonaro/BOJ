#include <iostream>
#include <math.h>
using namespace std;

/*
정수 N이 주어졌을 때, 소인수분해하는 프로그램을 작성하시오.
첫째 줄에 정수 N (1 ≤ N ≤ 10,000,000)이 주어진다.
*/

int main() {
	int N = 0;
	cin >> N;

	if (N == 1) {
		return 0;
	}

	for (; ; ) {
		bool isPrime = true;
		for (int i = 2; i <= sqrt(N); i++) {
			if (N % i == 0) {
				cout << i << endl;
				N /= i;
				isPrime = false;
				break;
			}
		}
		if (isPrime) {
			cout << N << endl;
			return 0;
		}
	}
}