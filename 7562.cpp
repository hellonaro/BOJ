#include <iostream>
#include <vector>
#include <queue>
#define REP(n) for(int i=0; i<n; i++)
using namespace std;

/*
체스판 위에 한 나이트가 놓여져 있다.
나이트는 몇 번 움직이면 목표 칸으로 이동할 수 있을까?
*/

vector<vector<int>> board;
queue<pair<int, int>> Q;
int I; // 체스판 한 변의 길이
int srcX, srcY, dstX, dstY;

int shift[4] = { -2, -1, 1, 2 };

bool isInRange(int x, int y) {
	if (x < 0 || x >= I) return false;
	if (y < 0 || y >= I) return false;
	return true;
}

void bfs(int x, int y) {
	if (x == dstX && y == dstY) {
		cout << board[x][y] << endl;
		return;
	}
	Q.pop();
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if(abs(shift[i]) == abs(shift[j])) continue;
			int nextX = x + shift[i], nextY = y + shift[j];
			if (isInRange(nextX, nextY) && board[nextX][nextY] == -1) {
				Q.push({ nextX, nextY });
				board[nextX][nextY] = board[x][y] + 1;
			}
		}
	}
	if (Q.empty()) return;
	bfs(Q.front().first, Q.front().second);
}

int main() {
	int T; cin >> T; //테스트 케이스 수
	REP(T) {
		cin >> I;
		vector<int> tmp(I, -1);
		board.assign(I, tmp);
		queue<pair<int, int>> empty;
		swap(Q, empty);
		cin >> srcX >> srcY >> dstX >> dstY;
		board[srcX][srcY] = 0;
		Q.push({ srcX, srcY });
		bfs(srcX, srcY);
	}
}