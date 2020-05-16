#include <stdio.h>

/*
세 개의 장대가 있고 첫 번째 장대에는 반경이 서로 다른 n개의 원판이 쌓여 있다. 
각 원판은 반경이 큰 순서대로 쌓여있다. 
이제 수도승들이 다음 규칙에 따라 첫 번째 장대에서 세 번째 장대로 옮기려 한다.

한 번에 한 개의 원판만을 다른 탑으로 옮길 수 있다.
쌓아 놓은 원판은 항상 위의 것이 아래의 것보다 작아야 한다.
이 작업을 수행하는데 필요한 이동 순서를 출력하는 프로그램을 작성하라. 
단, 이동 횟수는 최소가 되어야 한다.

첫째 줄에 옮긴 횟수 K를 출력한다.
두 번째 줄부터 수행 과정을 출력한다. 
두 번째 줄부터 K개의 줄에 걸쳐 두 정수 A B를 빈칸을 사이에 두고 출력하는데, 
이는 A번째 탑의 가장 위에 있는 원판을 B번째 탑의 가장 위로 옮긴다는 뜻이다.
*/

void hanoi(int n, int start, int goal) {
	int temp;
	if (n == 1) {
		printf("%d %d\n", start, goal);
		return 0;
	}

	if (start + goal == 3) temp = 3;
	else if (start + goal == 4) temp = 2;
	else temp = 1;

	hanoi(n - 1, start, temp);
	printf("%d %d\n", start, goal);
	hanoi(n - 1, temp, goal);
}

int main() {
	int num;
	int count = 1;
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		count *= 2;
	}
	printf("%d\n", count - 1);
	hanoi(num, 1, 3);
}