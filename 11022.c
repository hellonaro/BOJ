#include <stdio.h>

/*
두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.
첫째 줄에 테스트 케이스의 개수를 입력으로 받는다.
각 테스트 케이스마다 "Case #x: A + B = C" 형식으로 출력한다. 
*/

int main() {
	int num,a,b;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d %d", &a, &b);
		printf("Case #%d: %d + %d = %d\n", i + 1, a, b, a + b);
	}
}