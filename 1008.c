#include <stdio.h>

int main() {
	int a, b;
	double result;
	scanf("%d %d", &a, &b);
	result = (double)a / b;
	printf("%.10f\n", result);
}