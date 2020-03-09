#include <stdio.h>
#include <stdlib.h>

/*
정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.
  1. X가 3으로 나누어 떨어지면, 3으로 나눈다.
  2. X가 2로 나누어 떨어지면, 2로 나눈다.
  3. 1을 뺀다.

정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다.
연산을 사용하는 횟수의 최솟값을 출력하시오.
*/

int main() {
	int N;
	int* result;
	scanf("%d", &N);
	result = malloc(sizeof(int) * (N+1));
	result[1]= 0; result[2] = 1; result[3] = 1;
	for (int i = 4; i<=N; i++){
		int temp = result[i - 1];
		if (i % 3 == 0) {
			temp = result[i / 3] > temp ? temp : result[i / 3];
		}
		if (i % 2 == 0) {
			temp = result[i / 2] > temp ? temp : result[i / 2];
		}
		result[i] = temp + 1;
	}
	printf("%d", *(result+N));
}