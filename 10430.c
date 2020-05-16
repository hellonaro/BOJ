#include <stdio.h>

/*
(A+B)%C는 ((A%C) + (B%C))%C 와 같을까?
(A×B)%C는 ((A%C) × (B%C))%C 와 같을까?
세 수 A, B, C가 주어졌을 때, 위의 네 가지 값을 구하는 프로그램을 작성하시오.
*/

int main() {
	int a, b, c;
	int result1, result2, result3, result4;
	scanf("%d %d %d", &a, &b, &c);
	result1 = (a + b) % c;
	result2 = (a % c + b % c) % c;
	result3 = (a * b) % c;
	result4 = (a % c) * (b % c) % c;
	printf("%d\n", result1);
	printf("%d\n", result2);
	printf("%d\n", result3);
	printf("%d", result4);
}