#include <stdio.h>

/*
한수는 지금 (x, y)에 있다. 직사각형의 왼쪽 아래 꼭짓점은 (0, 0)에 있고, 오른쪽 위 꼭짓점은 (w, h)에 있다.
직사각형의 경계선까지 가는 거리의 최솟값을 구하는 프로그램을 작성하시오.
*/

int main() {
	int x, y, w, h;
	int horizontal, vertical, distance;

	scanf("%d%d%d%d", &x, &y, &w, &h);
	horizontal = x > w - x ? w - x : x;
	vertical = y > h - y ? h - y : y;
	distance = horizontal > vertical ? vertical : horizontal;

	printf("%d", distance);
}