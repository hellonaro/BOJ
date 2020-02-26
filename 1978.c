#include <stdio.h>
#include <math.h>

/*
주어진 수 N개 중에서 소수가 몇 개인지 찾아서 출력하는 프로그램을 작성하시오.
*/

int main() {
	int N, num, root_num, isPrime;
	int i, j;
	int result = 0;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &num);
		root_num = sqrt(num);
		isPrime = num == 1 ? 0 : 1;

		//소수 판별, num의 제곱근 이하까지 나눠봐도 충분
		for (j = 2; j <= root_num ; j++) {
			if (num % j == 0) {
				isPrime = 0;
				break;
			}
		}
		if (isPrime) result++;
	}
	printf("%d", result);
}