#include <stdio.h>

/*
정수 N개로 이루어진 수열 A와 정수 X가 주어진다. 
이때, A에서 X보다 작은 수를 모두 출력하는 프로그램을 작성하시오.
*/

int main() {
	int a,b,c;
	scanf("%d %d", &a,&b);
	for (int i=0; i < a; i++) {
		scanf("%d", &c);
		if (c < b)
			printf("%d ", c);
	}
}