#include <stdio.h>

/*
재귀를 이용한 fibonacci(N)이라는 함수가 호출했을 때,
0과 1이 각각 몇 번 return 되는지 구하는 프로그램을 작성하시오.
*/

int main(){
	int T;
	int N;
	int zero[41];
	int one[41];
	zero[0] = 1; zero[1] = 0;
	one[0] = 0; one[1] = 1;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		for (int j = 2; j <= N; j++) {
			zero[j] = zero[j - 1] + zero[j - 2];
			one[j] = one[j - 1] + one[j - 2];
		}
		printf("%d %d\n",zero[N],one[N]);
	}
}