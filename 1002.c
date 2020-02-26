#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
이석원은 조규현과 백승환에게 상대편 마린(류재명)의 위치를 계산하라는 명령을 내렸다.
조규현과 백승환은 각각 자신의 터렛 위치에서 현재 적까지의 거리를 계산했다.
조규현의 좌표(x1, y1)와 백승환의 좌표(x2, y2)가 주어지고, 조규현이 계산한 류재명과의 거리 r1과 백승환이 계산한 류재명과의 거리 r2가 주어졌을 때, 
류재명이 있을 수 있는 좌표의 수를 출력하는 프로그램을 작성하시오.
*/

int main() {
	int T;
	int x1, y1, r1;
	int x2, y2, r2;
	double distance;

	scanf("%d", &T);
	for(int i=0; i<T; i++){
		int x, y, r_sum, r_gap;
		scanf("%d%d%d%d%d%d", &x1, &y1, &r1, &x2, &y2, &r2);
		x = abs(x1 - x2);
		y = abs(y1 - y2);
		r_sum = r1 + r2;
		r_gap = abs(r1 - r2);
		distance = sqrt(x * x + y * y);

		if (r_sum < distance) printf("0");
		else if (r_sum == distance) printf("1");
		else if (r_gap < distance && distance < r_sum) printf("2");
		else if (distance == r_gap) printf("%d", r_gap == 0 ? -1 : 1);
		else printf("0");

		printf("\n");
	}
}