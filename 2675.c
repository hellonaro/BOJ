#include <stdio.h>
#include <string.h>

/*
문자열 S를 입력받은 후에, 각 문자를 R번 반복해 
새 문자열 P를 만든 후 출력하는 프로그램을 작성하시오. 
첫 번째 문자를 R번 반복하고, 두 번째 문자를 R번 반복하는 식으로 P를 만들면 된다.
*/

int main() {
	int test;
	int loop;
	char word[20];
	scanf("%d", &test);
	for (int i = 0; i < test; i++) {
		scanf("%d %s", &loop, &word);
		for (int j = 0; j < strlen(word); j++) {
			for (int k = 0; k < loop; k++) {
				printf("%c", word[j]);
			}
		}
		printf("\n");
	}
}