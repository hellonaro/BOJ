#define big 250
#include <stdio.h>

int main() {
	int N, M;
	int temp1=0, temp2=0, temp=0, change=big;
	char board[50][50];
	char chess1[8][8], chess2[8][8];

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if ((i + j) % 2 == 0) {
				chess1[i][j] = 'B';
				chess2[i][j] = 'W';
			}
			else {
				chess1[i][j] = 'W';
				chess2[i][j] = 'B';
			}
		}
	}

	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%s", board[i]);
	}

	for (int i = 0; i <= N-8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			temp1 = 0; temp2 = 0;
			for (int k = i; k < i + 8; k++) {
				for (int l = j; l < j + 8; l++) {
					if (chess1[k - i][l - j] != board[k][l])
						temp1++;
					if (chess2[k - i][l - j] != board[k][l])
						temp2++;
				}
			}
			temp = temp1 < temp2 ? temp1 : temp2;
			change = change < temp ? change : temp;
		}
	}
	printf("%d", change);
}