#include <stdio.h>

/*
2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.
*/

int main() {
	int n;
	int result[1001];
	scanf("%d", &n);
	result[1] = 1; result[2] = 2;
	for (int i = 3; i <= n; i++) {
		result[i] = (result[i - 1] + result[i - 2]) % 10007;
	}
	printf("%d", result[n]);
}