#include <stdio.h>
#include <string.h>

/*
알파벳 소문자로만 이루어진 단어 S가 주어진다. 
각각의 알파벳에 대해서, 단어에 포함되어 있는 경우에는 처음 등장하는 위치를,
포함되어 있지 않은 경우에는 -1을 출력하는 프로그램을 작성하시오.
*/

int main() {
	char word[100];
	char letter;
	int index;
	scanf("%s", &word);
	for (letter='a';letter<123;letter++){
		index = -1;
		for (int i = 0; i < strlen(word); i++) {
			if (letter == word[i]) {
				index = i;
				break;
			}
		}
		printf("%d ", index);
	}
}