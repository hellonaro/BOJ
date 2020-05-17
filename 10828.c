#include <stdio.h>
#include <string.h>

/*
정수를 저장하는 스택을 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.
명령은 총 다섯 가지이다.
 -push X: 정수 X를 스택에 넣는 연산이다.
 -pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
 -size: 스택에 들어있는 정수의 개수를 출력한다.
 -empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
 -top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/

int main() {
	int N;  //명령의 수
	int* stack;
	int top=-1;
	char inst[5];  //명령

	scanf("%d", &N);
	stack = (int*)malloc(4 * N);

	for (int i = 0; i < N; i++) {
		scanf("%s", &inst);
		if (!strcmp(inst, "push")) {
			scanf("%d", &stack[++top]);
		}
		else if (!strcmp(inst, "pop")) {
			if (top == -1) printf("-1\n");
			else printf("%d\n", stack[top--]);
		}
		else if (!strcmp(inst, "size")) {
			printf("%d\n", top+1);
		}
		else if (!strcmp(inst, "top")) {
			if (top == -1) printf("-1\n");
			else printf("%d\n", stack[top]);
		}
		else if (!strcmp(inst, "empty")) {
			if (top == -1) printf("1\n");
			else printf("0\n");
		}
		else {}
	}
}