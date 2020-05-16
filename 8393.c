#include <stdio.h>

/*
n이 주어졌을 때 1부터 n까지 합을 구하시오.
*/

int main() {
	int num;
	int sum = 0;
	scanf("%d", &num);
	for (int i = 1; i <= num; i++) {
		sum += i;
	}
	printf("%d", sum);
}