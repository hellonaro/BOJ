#include <iostream>
using namespace std;

/*
자연수 n과 정수 r가 주어졌을 때 이항 계수 n C r을 구하는 프로그램을 작성하시오.
*/

int main() {
	int n, r; cin >> n >> r;
	int ans = 1;
	for (int i = 0; i < r; i++) {
		ans *= (n - i);
	}
	for (int i = 2; i <= r; i++) {
		ans /= i;
	}
	cout << ans;
}