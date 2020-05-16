#include <stdio.h>
#include <math.h>

/*
세 개의 자연수 A, B, C가 주어질 때 
A×B×C를 계산한 결과에 0부터 9까지 
각각의 숫자가 몇 번씩 쓰였는지를 구하는 프로그램을 작성하시오.

예를 들어 A = 150, B = 266, C = 427 이라면 
A × B × C = 150 × 266 × 427 = 17037300 이 되고, 
계산한 결과 17037300 에는 0이 3번, 1이 1번, 3이 2번, 7이 2번 쓰였다.
*/

int main() {
	int a, b, c, result, length;
	char buf[10];
	int num[10] = { 0, };

	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	result = a * b * c;
	length = floor(log10(result))+1;
	sprintf(buf, "%d", result);

	for (int i = 0; i < length; i++) {
		int index = buf[i] - 48; //아스키코드를 이용한 char to int
		num[index] += 1;
	}
	
	for (int i = 0; i < 10; i++) {
		printf("%d\n", num[i]);
	}
}