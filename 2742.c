#include <stdio.h>

/*
자연수 N이 주어졌을 때, N부터 1까지 한 줄에 하나씩 출력하는 프로그램을 작성하시오.
*/

int main() {
	int num;
	scanf("%d", &num);
	for (int i = num; i > 0; i--) {
		printf("%d\n",i);
	}	
}