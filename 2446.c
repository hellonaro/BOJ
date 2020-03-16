#include <stdio.h>

/*
규칙을 유추한 뒤 별을 찍어 보세요.
*/

int main() {
	int N;
	scanf("%d", &N);
	for (int i = N; 0 < i; i--) {
		for (int j = 0; j < N-i; j++) {
			printf(" ");
		}
		for (int k = 0; k < 2*i-1; k++) {
			printf("*");
		}
		printf("\n");
	}
	for (int i = 2; i <= N;i++) {
		for (int j = 0; j < N-i; j++ ) {
			printf(" ");
		}
		for (int k = 0; k < 2 * i - 1; k++) {
			printf("*");
		}
		printf("\n");
	}
}