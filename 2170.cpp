#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

/*
매우 큰 도화지에 자를 대고 선을 그으려고 한다. 
선을 그을 때에는 자의 한 점에서 다른 한 점까지 긋게 된다. 
선을 그을 때에는 이미 선이 있는 위치에 겹쳐서 그릴 수도 있는데, 여러 번 그은 곳과 한 번 그은 곳의 차이를 구별할 수 없다고 하자.
이와 같은 식으로 선을 그었을 때, 그려진 선(들)의 총 길이를 구하는 프로그램을 작성하시오. 
선이 여러 번 그려진 곳은 한 번씩만 계산한다.
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N; cin >> N;
	deque<pair<int, int>> coord;
	int sum = 0;
	int x, y;

	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		coord.emplace_back(x, y);
	}
	sort(coord.begin(), coord.end());

	int start = coord[0].first;
	int end = coord[0].second;
	for (int i = 1; i < N; i++) {
		if (coord[i].first <= end) {
			end = (end > coord[i].second) ? end : coord[i].second;
		}
		else {
			sum += end - start;
			start = coord[i].first;
			end = coord[i].second;
		}
	}
	sum += end - start;
	cout << sum;
}