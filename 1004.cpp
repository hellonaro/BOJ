#include <iostream>
#include <cmath>
using namespace std;

/*
은하수 지도, 출발점, 도착점이 주어졌을 때 
어린 왕자에게 필요한 최소의 행성계 진입/이탈 횟수를 구하는 프로그램을 작성해 보자. 
(행성계의 경계가 맞닿거나 서로 교차하는 경우는 없다고 가정한다.
또한, 출발점이나 도착점이 행성계 경계에 걸쳐진 경우 역시 입력으로 주어지지 않는다.)
*/

double getDistance(int x, int y, int cx, int cy) {
	int gapX = x - cx;
	int gapY = y - cy;
	int distance = sqrt(gapX * gapX + gapY * gapY);

	return distance;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); 
	cout.tie(0);

	int T; cin >> T; // 테스트 케이스 수
	int x1, y1, x2, y2;
	int n, count;
	for (int i = 0; i < T; i++) {
		cin >> x1 >> y1;  // 출발점 좌표
		cin >> x2 >> y2;  // 도착점 좌표
		cin >> n;
		count = 0; // 행성계 진입,이탈 횟수

		for (int i = 0; i < n; i++) {
			int cx, cy; cin >> cx >> cy; // 행성계 중점 좌표
			int r; cin >> r; // 행성계 반지름

			bool inside1 = false, inside2 = false;  // 출발점, 도착점이 행성계 안에 존재하는지 여부
			if (r > getDistance(x1, y1, cx, cy)) inside1 = true;
			if (r > getDistance(x2, y2, cx, cy)) inside2 = true;
			if (inside1 != inside2) count++;
		}
		cout << count << "\n";
	}
}