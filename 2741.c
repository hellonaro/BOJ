#include <stdio.h>

/*
자연수 N이 주어졌을 때, 1부터 N까지 한 줄에 하나씩 출력하는 프로그램을 작성하시오.
*/

int main() {
	int num;
	scanf("%d", &num);
	for (int i = 1; i <= num; i++) {
		printf("%d\n",i);
	}	
}