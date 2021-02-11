#include <iostream>
using namespace std;

/*
한수는 2^N x 2^N 크기의 2차원 배열을 Z모양으로 탐색하려고 한다. 
예를 들어, 2×2배열을 왼쪽 위칸, 오른쪽 위칸, 왼쪽 아래칸, 오른쪽 아래칸 순서대로 방문하면 Z모양이다.
N이 주어졌을 때, r행 c열을 몇 번째로 방문했는지 출력하는 프로그램을 작성하시오.
*/

int zzz(int x, int y, int size) {  // size의 블록을 4등분한 것 중 몇 번째 칸인지 반환
	if (size == 1) return 0;
	int half = size / 2;
	int quarter = half * half;
	if (x < half && y < half) { // 1번재 칸
		return zzz(x, y, half);
	}
	if (x < half && y >= half) { // 2번재 칸
		return quarter + zzz(x, y-half, half);
	}
	if (x >= half && y < half) { // 3번재 칸
		return quarter * 2 + zzz(x-half, y, half);
	}
	if (x >= half && y >= half) { // 4번재 칸
		return quarter * 3 + zzz(x-half, y-half, half);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, r, c; cin >> N >> r >> c;
	int size = 1 << N;
	cout << zzz(r, c, size);
}