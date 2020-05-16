#include <stdio.h>

/*
오른쪽 정렬로 N번째 줄에 별 N개를 찍는 문제 
*/

int main() {
	int a;
	scanf("%d", &a);
	for (int i=1; i <= a; i++) {
		for (int k = a - i; k > 0; k--) {
			printf(" ");
		}
		for (int j = 0; j < i; j++) {
			printf("*");
		}
		printf("\n");
	}
}