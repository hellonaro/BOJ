#include <iostream>
using namespace std;

/*
n C m 의 끝자리 0의 개수를 출력하는 프로그램을 작성하시오.
*/

int main() {
	int n, m; cin >> n >> m;
	int gap = n - m;
	int num_two = 0, num_five = 0;  // 2의 개수, 5의 개수
	long long power_two, power_five;
	int ans;

	for (power_two = 2; n >= power_two;) {
		num_two += n / power_two;
		power_two *= 2;
	}
	for (power_two = 2; gap >= power_two;) {
		num_two -=  gap / power_two;
		power_two *= 2;
	}
	for (power_two = 2; m >= power_two;) {
		num_two -= m / power_two;
		power_two *= 2;
	}

	for (power_five = 5; n >= power_five;) {
		num_five += n / power_five;
		power_five *= 5;
	}
	for (power_five = 5; gap >= power_five;) {
		num_five -= gap / power_five;
		power_five *= 5;
	}
	for (power_five = 5; m >= power_five;) {
		num_five -= m / power_five;
		power_five *= 5;
	}

	ans = num_two > num_five ? num_five : num_two;
	cout << ans;
}