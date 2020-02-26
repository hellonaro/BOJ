#include <stdio.h>

/*
666은 종말을 나타내는 숫자라고 한다. 
따라서, 많은 블록버스터 영화에서는 666이 들어간 제목을 많이 사용한다. 
영화감독 숌은 세상의 종말 이라는 시리즈 영화의 감독이다.
종말의 숫자란 어떤 수에 6이 적어도 3개이상 연속으로 들어가는 수를 말한다.
제일 작은 종말의 숫자는 666이고, 그 다음으로 큰 수는 1666, 2666, 3666, .... 과 같다.
따라서, 숌은 첫 번째 영화의 제목은 세상의 종말 666, 두 번째 영화의 제목은 세상의 종말 1666 이렇게 이름을 지을 것이다. 
일반화해서 생각하면, N번째 영화의 제목은 N번째로 작은 종말의 숫자와 같다.
숌이 만든 N번째 영화의 제목에 들어간 숫자를 출력하는 프로그램을 작성하시오.
숌은 이 시리즈를 항상 차례대로 만들고, 다른 영화는 만들지 않는다.
*/


int main() {
	int num;
	int head = -1, body=0, tail = 0;
	int N;
	int count;

	scanf("%d", &N);
	for (int i = 0; i < N;) {
		count = 0;
		for (int j = head+1; j % 10 == 6; j/=10) {
			count++;
		}
		if (count == 0) {
			body = 666;
			tail = 0;
			i++;
		}
		else if (count == 1) {
			body = 660;
			for (tail = -1; tail < 9&&i<N ; tail++, i++);
		}
		else if (count == 2) {
			body = 600;
			for (tail = -1; tail < 99&&i<N; tail++, i++);
		}
		else {
			body = 0;
			for (tail = -1; tail < 999&&i<N; tail++, i++);
		}
		head++;
	}
	num = head*1000 + body + tail;
	printf("%d", num);
}