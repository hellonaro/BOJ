#include <iostream>
using namespace std;

/*
두 개의 자연수를 입력받아 최대 공약수와 최소 공배수를 출력하는 프로그램을 작성하시오.
*/

int main() {
	int a, b; cin >> a >> b;
	int GCD, LCM;

	int dividend, divisor, remainder;
	dividend = a > b ? a : b;
	divisor = a > b ? b : a;
	remainder = dividend % divisor;

	for (; remainder != 0; ) {
		dividend = divisor;
		divisor = remainder;
		remainder = dividend % divisor;
	}
	LCM = divisor;
	GCD = a * b / LCM;
	cout << LCM << endl << GCD << endl;
}