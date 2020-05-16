#include <stdio.h>

/*
준규가 가지고 있는 동전은 총 N종류이고, 각각의 동전을 매우 많이 가지고 있다.
동전을 적절히 사용해서 그 가치의 합을 K로 만들려고 한다. 
이때 필요한 동전 개수의 최솟값을 구하는 프로그램을 작성하시오.
*/

int main(){
	int N, K;
	int value[10];
	int Q, R;
	int count=0;

	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &value[i]);
	}

	R = K;
	for (int i = N - 1; R!=0 ; i--) {
		if (R >= value[i]) {
			Q = R / value[i];
			R = R % value[i];
			count += Q;
		}
	}

	printf("%d", count);
}