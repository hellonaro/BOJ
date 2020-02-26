#include <stdio.h>

/*
어떤 양의 정수 X의 자리수가 등차수열을 이룬다면, 그 수를 한수라고 한다.
1000보다 작거나 같은 자연수 N이 주어졌을 때, 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력하는 프로그램을 작성하시오.
*/

int han(int n){
	int count=0;
	int digit[4];
	for (int i = 1; i <= n; i++) {
		int num = i;
		if (i < 100) count++;
		else if (i > 999);
		else {
			for (int j = 0; num ; num /=10, j++)
				digit[j] = num % 10;
			if (digit[0] + digit[2] == digit[1]*2)
				count++;
		}
	}
	return count;
}

int main() {
	int num;
	scanf("%d", &num);
	printf("%d", han(num));
}