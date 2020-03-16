#include <stdio.h>

/*
점의 좌표를 입력받아 그 점이 어느 사분면에 속하는지 알아내는 프로그램을 작성하시오. 
단, x좌표와 y좌표는 모두 양수나 음수라고 가정한다.
*/

int main() {
	int x, y;
	scanf("%d %d", &x, &y);

	if (x * y > 0) {
		if (x > 0) printf("1");
		else printf("3");
	}
	else {
		if (x > 0) printf("4");
		else printf("2");
	}
}