#include <stdio.h>

/*
맨 위층부터 시작해서 아래에 있는 수 중 하나를 선택하여 아래층으로 내려올 때, 
이제까지 선택된 수의 합이 최대가 되는 경로를 구하는 프로그램을 작성하라. 

아래층에 있는 수는 현재 층에서 선택된 수의 대각선 왼쪽 또는 대각선 오른쪽에 있는 것 중에서만 선택할 수 있다.
삼각형의 크기는 1 이상 500 이하이다. 
삼각형을 이루고 있는 각 수는 모두 정수이며, 범위는 0 이상 9999 이하이다.
*/

int main() {
	int N;
	int max = 0;
	int tri[501][501];
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &tri[i][j]);
		}
	}
	if (N > 1) {
		tri[2][1] += tri[1][1];
		tri[2][2] += tri[1][1];
	}
	for (int i = 3; i <= N; i++) {
		int j = 1;
		tri[i][j] += tri[i - 1][j];
		for (j = 2; j < i; j++) {
			tri[i][j] += tri[i - 1][j - 1] > tri[i - 1][j] ? tri[i - 1][j-1] : tri[i - 1][j];
		}
		tri[i][j] += tri[i - 1][j - 1];
	}
	for (int i = 1; i <= N; i++) {
		if (max < tri[N][i]) max = tri[N][i];
	}
	printf("%d", max);
}