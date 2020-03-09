#include <stdio.h>

/*
정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.
*/

int main() {
	int T, n;
	int result[12];
	result[1] = 1; result[2] = 2; result[3] = 4;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &n);
		for (int j = 4; j <= n; j++) {
			result[j] = result[j - 3] + result[j - 2] + result[j - 1];
		}
		printf("%d\n", result[n]);
	}
}