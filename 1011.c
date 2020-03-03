#include <stdio.h>
#include <math.h>

/*
공간 이동 장치로 x지점에서 y지점을 향해 최소한의 작동 횟수로 이동하려 한다.
장치는 이전 작동시기에 k광년을 이동하였을 때 k-1 , k 혹은 k+1 광년만을 다시 이동할 수 있다. 
예를 들어, 이 장치를 처음 작동시킬 경우 -1 , 0 , 1 광년을 이론상 이동할 수 있으나 
사실상 음수 혹은 0 거리만큼의 이동은 의미가 없으므로 1 광년을 이동할 수 있으며, 
그 다음에는 0 , 1 , 2 광년을 이동할 수 있는 것이다.
안전성을 위하여 y지점에 도착하기 바로 직전의 이동거리는 반드시 1광년으로 하려 할 때,
x지점부터 정확히 y지점으로 이동하는데 필요한 공간 이동 장치 작동 횟수의 최솟값을 구하는 프로그램을 작성하라.
*/

int main() {
	int T;
	int x, y;
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d %d", & x, &y);
		double distance = (double) y - x;
		double k;
		k = (-2 + sqrt(16 * distance)) / 2; 
		if (k - (int)k == 0)
			printf("%d\n", (int)k);
		else
			printf("%d\n", (int)k + 1);
	}
}