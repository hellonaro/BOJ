#include <stdio.h>

/*
n이 주어졌을 때, n번째 피보나치 수를 구하는 프로그램을 작성하시오.
n은 90보다 작거나 같은 자연수이다.
*/

int main(){
	int n;
	unsigned long long fibo[91];
	fibo[0] = 0;
	fibo[1] = 1;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	printf("%llu", fibo[n]);
}