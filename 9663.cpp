#include <iostream>
using namespace std;

/*
N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.
N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.\
*/

int N;
int Count;
int board[15][15];

void addQueen(int x, int y) {
	for (int i = x - 1; i >= 0; i--) board[i][y]++;
	for (int i = x + 1; i < N; i++) board[i][y]++;
	for (int i = y - 1; i >= 0; i--) board[x][i]++;
	for (int i = y + 1; i < N; i++) board[x][i]++;
	for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--) board[i][j]++;
	for (int i = x + 1, j = y + 1; i < N && j < N; i++, j++) board[i][j]++;
	for (int i = x - 1, j = y + 1; i >= 0 && j < N; i--, j++) board[i][j]++;
	for (int i = x + 1, j = y - 1; i < N && j >= 0; i++, j--) board[i][j]++;
}
void removeQueen(int x, int y) {
	for (int i = x - 1; i >= 0; i--) board[i][y]--;
	for (int i = x + 1; i < N; i++) board[i][y]--;
	for (int i = y - 1; i >= 0; i--) board[x][i]--;
	for (int i = y + 1; i < N; i++) board[x][i]--;
	for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--) board[i][j]--;
	for (int i = x + 1, j = y + 1; i < N && j < N; i++, j++) board[i][j]--;
	for (int i = x - 1, j = y + 1; i >= 0 && j < N; i--, j++) board[i][j]--;
	for (int i = x + 1, j = y - 1; i < N && j >= 0; i++, j--) board[i][j]--;
}

void setQueen(int x) {  // x번째줄의 퀸 할당 (퀸은 각 줄에 하나만 가능)
	if (x == N) {
		Count++;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (board[x][i] == 0) {
			addQueen(x, i);
			setQueen(x+1);
			removeQueen(x, i);
		}
	}
}

int main() {
	cin >> N;
	Count = 0;
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			board[i][j] = 0;
		}
	}
	setQueen(0);
	cout << Count;
}