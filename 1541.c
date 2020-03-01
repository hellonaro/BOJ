#include <stdio.h>

/*
세준이는 길이가 최대 50인 식을 만들었다.
식은 ‘0’~‘9’, ‘+’, 그리고 ‘-’만으로 이루어져 있고, 가장 처음과 마지막 문자는 숫자이다.
그리고 연속해서 두 개 이상의 연산자가 나타나지 않고, 5자리보다 많이 연속되는 숫자는 없다.
수는 0으로 시작할 수 있을 때, 괄호를 적절히 쳐서 이 식의 값을 최소로 만들어라.
*/

int isOperator(char c) {
	if (c == '+' || c == '-') return 1;
	else return 0;
}

int main() {
	char formula[50];
	char buf[6]="000000";
	int number=0;
	int minus = 0; // 식에서 -가 아직 안나왔다면 0
	int result = 0;
	scanf("%s", formula);

	for (int i = 0, j = 0; formula[i] != 0; i++, j++) {
		buf[j] = formula[i];

		if (isOperator(formula[i])) {
			buf[j] = 0;
			number = atoi(buf);
			if (minus) result -= number;
			else result += number;
			if (formula[i] == '-') minus++;
			j = -1;
			continue;
		}
		else if (formula[i + 1]==0) {
			buf[j + 1] = 0;
			number = atoi(buf);
			if (minus) result -= number;
			else result += number;
			break;
		}
	}

	printf("%d", result);
}