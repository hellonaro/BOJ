#include <iostream>
using namespace std;

/*
수직선 위에 선분을 여러 개 그릴 것이다.
선분을 겹치게 그리는 것도 가능하다.
선분을 모두 그렸을 때, 수직선 위에 그려진 선분 길이의 총합은 얼마인지 구하는 프로그램을 작성하시오.

첫째 줄에 수직선 위에 그릴 선분의 개수 N이 주어진다. (1 ≤ N ≤ 100,000)
둘째 줄 부터 N개의 줄에 좌표를 나타내는 정수쌍 (x, y)가 주어진다.
이는 [x, y] 구간 (x와 y를 포함하는 구간)에 선분을 그린다는 의미이다.
좌표는 x가 증가하는 순으로, x가 같다면 y가 증가하는 순으로 주어진다.
*/

int main() {
	int N; cin >> N;
	int x, y; cin >> x >> y;

	int sum = 0;
	int start = x;
	int end = y;
	for (int i = 1; i < N; i++) {
		cin >> x >> y;
		if (end >= x) end = (end > y) ? end : y;
		else {
			sum += end - start;
			start = x; end = y;
		}
	}
	sum += end - start;
	cout << sum;
}