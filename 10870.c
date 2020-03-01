#include <stdio.h>

/*
n이 주어졌을 때, n번째 피보나치 수를 구하는 프로그램을 작성하시오.
*/

int fibo(n) {
	int result;
	if (n == 0) return 0;
	if (n == 1) return 1;
	result = fibo(n - 1) + fibo(n - 2);
	return result;
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d", fibo(n));
}