#include <stdio.h>

/*
45656이란 수를 보자.
이 수는 인접한 모든 자리수의 차이가 1이 난다. 이런 수를 계단 수라고 한다.
세준이는 수의 길이가 N인 계단 수가 몇 개 있는지 궁금해졌다.
N이 주어질 때, 길이가 N인 계단 수가 총 몇 개 있는지 구하는 프로그램을 작성하시오.
정답은 1,000,000,000으로 나눈 나머지를 출력한다.
*/

int main() {
	int stair[101][10]; // [i][j]에서 i는 숫자열의 길이, j는 끝자리 수
	int N;
	int result = 0;
	stair[1][0] = 0;
	for (int i = 1; i < 10; i++) {
		stair[1][i] = 1;
	}
	scanf("%d", &N);
	
	// 길이가 i-1인 숫자열 뒤에 수를 하나 추가하면서 길이 i인 숫자열을 만듦
	for (int i = 2; i < N+1; i++) {
		stair[i][0] = stair[i - 1][1];
		for (int j = 1; j < 9; j++) {
			stair[i][j] = stair[i - 1][j - 1] + stair[i - 1][j + 1];
			stair[i][j] %= 1000000000;
		}
		stair[i][9] = stair[i - 1][8];
	}

	for (int i = 0; i < 10; i++) {
		result += stair[N][i];
		result %= 1000000000;
	}
	printf("%d", result);
}