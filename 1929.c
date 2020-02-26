#include <stdio.h>
#include <math.h>

/*
M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.
*/

int main() {
	int start, end, root, isPrime;
	int i, j;

	scanf("%d",&start);
	scanf("%d",&end);

	for (i = start; i <= end; i++) {
		isPrime = i == 1 ? 0 : 1;
		root = sqrt(i);
		for (j = 2; j <= root; j++) {
			if (i % j == 0) {
				isPrime = 0;
				break;
			}
		}
		if (isPrime) 
			printf("%d\n", i);
	}
}