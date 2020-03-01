#include <stdio.h>

/*
영어 대소문자와 띄어쓰기만으로 이루어진 문자열이 주어진다.
이 문자열에는 몇 개의 단어가 있을까? 이를 구하는 프로그램을 작성하시오.
단, 한 단어가 여러 번 등장하면 등장한 횟수만큼 모두 세어야 한다.
공백이 연속해서 나오는 경우는 없으며
또한 문자열의 앞과 뒤에는 공백이 있을 수도 있다.
*/

int main() {
	int count = 1;
	int i;
	char c=0;
	char last;
	for ( i=0 ; c!='\n' ; i++ ) {
		last = c;
		scanf("%c",&c);
		if ( i!=0 && c==' ' ) count++;
	}

	if (i < 2) {
		printf("0"); 
		return;
	}
	if (last == ' ') count--;
	printf("%d", count);
}