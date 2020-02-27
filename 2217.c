#include <stdio.h>
#include <stdlib.h>

/*
N(1≤N≤100,000)개의 로프가 있다.
이 로프를 이용하여 이런 저런 물체를 들어올릴 수 있다.
각각의 로프는 그 굵기나 길이가 다르기 때문에 들 수 있는 물체의 중량이 서로 다를 수도 있다.
하지만 여러 개의 로프를 병렬로 연결하면 각각의 로프에 걸리는 중량을 나눌 수 있다. 
k개의 로프를 사용하여 중량이 w인 물체를 들어올릴 때,
각각의 로프에는 모두 고르게 w/k 만큼의 중량이 걸리게 된다.
각 로프들에 대한 정보가 주어졌을 때, 
이 로프들을 이용하여 들어올릴 수 있는 물체의 최대 중량을 구해내는 프로그램을 작성하시오.
모든 로프를 사용해야 할 필요는 없으며, 임의로 몇 개의 로프를 골라서 사용해도 된다.
단, 각각의 로프는 한 개씩만 존재한다.
*/

int main() {
	int N;
	int max=0;
	scanf("%d", &N);
	int *rope =(int *)malloc(sizeof(int) * N+1);
	rope[0] = -1;
	for (int i = 1; i < N+1; i++) {
		scanf("%d", &rope[i]);
	}
	
	//최대힙 구성
	for (int i = 2; i < N + 1; i++) {
		int n = i;
		do {
			int root = n / 2;
			if (rope[root] < rope[n]) {
				int temp = rope[root];
				rope[root] = rope[n];
				rope[n] = temp;
			}
			else break;
			n = root;
		} while (n != 1);
	}
	//힙정렬
	for (int i = N; i > 0; i--) {
		int temp = rope[1];
		rope[1] = rope[i];
		rope[i] = temp;

		int root = 1;
		int n = 2;
		do {
			n = 2 * root;
			if (n < i-1 && rope[n] < rope[n + 1]) n++;
			if (n < i && rope[root] < rope[n]) {
				temp = rope[root];
				rope[root] = rope[n];
				rope[n] = temp;
			}
			root = n;
		} while (n < i);
	}
	for (int i = 1; i < N + 1; i++) {
		int temp = rope[i] * (N+1-i);
		if (max < temp) max = temp;
	}

	printf("%d", max);
}