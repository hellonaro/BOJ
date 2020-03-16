#include <stdio.h>

/*
규칙을 유추한 뒤 별을 찍어 보세요.
*/

int main() {
	int N;
	int first, last;
	scanf("%d", &N);
	
	if (N % 2 == 0)
		first = N / 2;
	else
		first = N / 2 + 1;
	last = N - first;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < first; j++) {
			printf("* ");
		}
		printf("\n");
		for (int j = 0; j < last; j++) {
			printf(" *");
		}
		printf("\n");
	}
}