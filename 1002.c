#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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