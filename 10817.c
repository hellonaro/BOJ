#include <stdio.h>

/*
세 정수 A, B, C가 주어진다. 이때, 두 번째로 큰 정수를 출력하는 프로그램을 작성하시오. 
*/

int main() {
	int a, b, c, mid;
	scanf("%d %d %d", &a, &b, &c);
	if (a >= b) {
		if (a >= c) {
			if (b >= c)
				mid = b;
			else
				mid = c;
		}
		else
			mid = a;
	}
	else {
		if (b >= c) {
			if (a >= c)
				mid = a;
			else
				mid = c;
		}
		else
			mid = b;
	}
	printf("%d", mid);
}