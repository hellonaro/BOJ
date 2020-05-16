#include <stdio.h>
#include <math.h>

/*
자연수 M과 N이 주어질 때
M이상 N이하의 자연수 중 소수인 것을 모두 골라 
이들 소수의 합과 최솟값을 찾는 프로그램을 작성하시오.
*/

int main() {
	int start, end, root, isPrime;
	int i, j;
	int min;
	int sum = 0;

	scanf("%d",&start);
	scanf("%d", &end);

	for (i = start; i <= end; i++) {
		isPrime = i == 1 ? 0 : 1;
		// 소수 판별, num의 제곱근 이하까지 나눠도 충분
		root = sqrt(i);
		for (j = 2; j <= root; j++) {
			if (i % j == 0) {
				isPrime = 0;
				break;
			}
		}
		if (isPrime) {
			if (sum == 0) min = i;
			sum += i;
		}
	}
	if (sum == 0) printf("-1");
	else printf("%d\n%d", sum, min);
}