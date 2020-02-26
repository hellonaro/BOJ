#include <stdio.h>
#include <string.h>

/*
알파벳 대소문자로 된 단어가 주어지면, 이 단어에서 가장 많이 사용된 알파벳이 무엇인지 알아내는 프로그램을 작성하시오. 단, 대문자와 소문자를 구분하지 않는다.
*/

int main() {
	char* word = (char*)malloc(1000000);
	int letter[26] = { 0, };
	int length;
	int max, preMax, index;
	scanf("%s", word);
	length = strlen(word);
	for (int i = 0; i < length; i++) {
		if (97 <= word[i]) word[i] -= 32;
		letter[word[i] - 65]++;
	}
	max = letter[0];
	preMax = 0;
	index = 0;
	for (int i = 1; i < 26; i++) {
		if (max < letter[i]) {
			max = letter[i];
			index = i;
		}
		else if (max == letter[i]) {
			preMax = letter[i];
		}
	}
	if (max == preMax) printf("?");
	else printf("%c", index+65);
}