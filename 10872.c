#include <stdio.h>

/*
0보다 크거나 같은 정수 N이 주어진다. 이때, N!을 출력하는 프로그램을 작성하시오.
*/

int facto(int n){
	int ans = 1;
	if (n == 0) return 1;
	else {
		for (int i = 1; i <= n; i++)
			ans *= i;
	}
	return ans;
}

int main() {
	int num;
	scanf("%d", &num);
	printf("%d", facto(num));
}