#define big 250
#include <stdio.h>

/*
지민이는 자신의 저택에서 MN개의 단위 정사각형으로 나누어져 있는 M*N 크기의 보드를 찾았다. 
어떤 정사각형은 검은색으로 칠해져 있고, 나머지는 흰색으로 칠해져 있다. 지민이는 이 보드를 잘라서 8*8 크기의 체스판으로 만들려고 한다.
체스판은 검은색과 흰색이 번갈아서 칠해져 있어야 한다. 
구체적으로, 각 칸이 검은색과 흰색 중 하나로 색칠되어 있고, 변을 공유하는 두 개의 사각형은 다른 색으로 칠해져 있어야 한다. 
따라서 이 정의를 따르면 체스판을 색칠하는 경우는 두 가지뿐이다. 하나는 맨 왼쪽 위 칸이 흰색인 경우, 하나는 검은색인 경우이다.
보드가 체스판처럼 칠해져 있다는 보장이 없어서, 지민이는 8*8 크기의 체스판으로 잘라낸 후에 몇 개의 정사각형을 다시 칠해야겠다고 생각했다.
당연히 8*8 크기는 아무데서나 골라도 된다. 지민이가 다시 칠해야 하는 정사각형의 최소 개수를 구하는 프로그램을 작성하시오.
*/

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