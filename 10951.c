#include <stdio.h>

/*
두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.
입력은 여러 개의 테스트 케이스로 이루어져 있다.
*/

int main() {
	int a, b;
	//scanf는 EOF의 경우 -1을 리턴한다
	while (scanf("%d %d", &a, &b)!=-1) {
		printf("%d\n",a+b);
	}
}