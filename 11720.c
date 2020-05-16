#include <stdio.h>
#include <stdlib.h>

/*
N개의 숫자가 공백 없이 쓰여있다. 이 숫자를 모두 합해서 출력하는 프로그램을 작성하시오.
*/

int main() {
	int num;
	int sum = 0;
	scanf("%d", &num);
	char* str = (char*)malloc(num);
	scanf("%s", str);
	for (int i = 0; i < num; i++) {
		sum += str[i] - 48;
	}
	printf("%d", sum);
}