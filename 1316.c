#include <stdio.h>
#include <string.h>

/*
그룹 단어란 단어에 존재하는 모든 문자에 대해서, 각 문자가 연속해서 나타나는 경우만을 말한다. 
예를 들면, ccazzzzbb는 c, a, z, b가 모두 연속해서 나타나고, 
kin도 k, i, n이 연속해서 나타나기 때문에 그룹 단어이지만, 
aabbbccb는 b가 떨어져서 나타나기 때문에 그룹 단어가 아니다.
단어 N개를 입력으로 받아 그룹 단어의 개수를 출력하는 프로그램을 작성하시오.
*/

int main() {
	int test, count, length;
	int i, j;
	char input[101];
	int letter[26];

	count = 0;
	scanf("%d", &test);
	for (i = 0; i < test; i++) {
		memset(letter, 0, sizeof(letter));
		scanf("%s", input);
		length = strlen(input);

		letter[input[0] - 97] = 1;
		for (j = 1; j < length; j++) {
			if (input[j - 1] != input[j]) {
				if (letter[input[j] - 97] != 0) break;
				else letter[input[j] - 97] = 1;
			}
		}
		if (j == length) count++;
	}
	printf("%d", count);
}