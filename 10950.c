#include <stdio.h>

/*
두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.
첫째 줄에 테스트 케이스 수를 입력으로 받는다.
*/

int main() {
	int n;
	int a, b;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
        printf("%d\n",a+b);
	}
}