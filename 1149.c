#include <stdio.h>
#include <stdlib.h>

/*
RGB거리에는 집이 N개 있다. 1번 집부터 N번 집이 순서대로 있다.
집은 빨강, 초록, 파랑 중 하나의 색으로 칠해야 한다. 
각각의 집을 빨강, 초록, 파랑으로 칠하는 비용이 주어졌을 때, 
아래 규칙을 만족하면서 모든 집을 칠하는 비용의 최솟값을 구해보자.

	1. 1번 집의 색은 2번 집의 색과 같지 않아야 한다.
	2. N번 집의 색은 N-1번 집의 색과 같지 않아야 한다.
	3. i(2 ≤ i ≤ N-1)번 집의 색은 i-1번, i+1번 집의 색과 같지 않아야 한다.
*/

int main() {
	int N;
	int* R; int* G; int* B;
	int result;
	scanf("%d", &N);
	R = (int*)malloc(sizeof(int) * N);
	G = (int*)malloc(sizeof(int) * N);
	B = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", R+i, G+i, B+i);
	}
	for (int i = 1; i < N; i++) {
		R[i] += G[i-1] > B[i-1] ? B[i-1] : G[i-1];
		G[i] += R[i-1] > B[i-1] ? B[i-1] : R[i-1];
		B[i] += R[i-1] > G[i-1] ? G[i-1] : R[i-1];
	}
	result = R[N - 1];
	if (result > G[N - 1]) result = G[N - 1];
	if (result > B[N - 1]) result = B[N - 1];

	printf("%d", result);
}