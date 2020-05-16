#include <stdio.h>
#include <stdlib.h>

/*
N개의 정수가 주어진다. 이때, 최솟값과 최댓값을 구하는 프로그램을 작성하시오.
*/

int main() {
	int a,big,small;
	scanf("%d", &a);
	int* num = (int*)malloc(sizeof(int) * a);

	for (int i = 0; i < a; i++)
		scanf("%d ",&num[i]);

	big = num[0];
	small = num[0];

	for (int i = 1; i < a; i++) {
		if (big < num[i]) big = num[i];
		if (small > num[i]) small = num[i];
	}

	printf("%d %d", small, big);
	free(num);
}