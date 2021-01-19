#include <iostream>
#include <deque>
using namespace std;

/*
게임 시작 전 스도쿠 판에 쓰여 있는 숫자들의 정보가 주어질 때 모든 빈 칸이 채워진 최종 모습을 출력하는 프로그램을 작성하시오.
아홉 줄에 걸쳐 한 줄에 9개씩 게임 시작 전 스도쿠판 각 줄에 쓰여 있는 숫자가 한 칸씩 띄워서 차례로 주어진다. 
스도쿠 판의 빈 칸의 경우에는 0이 주어진다. 스도쿠 판을 규칙대로 채울 수 없는 경우의 입력은 주어지지 않는다.
*/

int board[9][9];
deque<pair<int, int>> blank;
bool foundAns;

void getRange(int x, int y, bool* range) {
	for (int i = 0; i < 9; i++) {
		if (board[x][i] > 0) range[board[x][i]] = false;
	}
	for (int i = 0; i < 9; i++) {
		if (board[i][y] > 0) range[board[i][y]] = false;
	}
	x = (x / 3) * 3;
	y = (y / 3) * 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[x + i][y + j] > 0) range[board[x + i][y + j]] = false;
		}
	}
}

void sudoku(int n) { // n번째 빈칸 채우기
	if (n == blank.size()) {
		foundAns = true;
		return;
	}

	bool range[10];
	for (int i = 0; i < 10; i++) range[i] = true;
	int x = blank[n].first;
	int y = blank[n].second;
	getRange(x, y, range);

	for (int i = 1; i < 10; i++) {
		if (range[i]) {
			board[x][y] = i;
			sudoku(n + 1);
			if (foundAns) return;
			board[x][y] = 0;
		}	
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	foundAns = false;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) {
				blank.push_back(make_pair(i, j));
			}
		}
	}
	
	sudoku(0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
}