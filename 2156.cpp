#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
효주는 포도주 시식회에 갔다. 그 곳에 갔더니, 테이블 위에 다양한 포도주가 들어있는 포도주 잔이 일렬로 놓여 있었다. 
효주는 포도주 시식을 하려고 하는데, 여기에는 다음과 같은 두 가지 규칙이 있다.

1. 포도주 잔을 선택하면 그 잔에 들어있는 포도주는 모두 마셔야 하고, 마신 후에는 원래 위치에 다시 놓아야 한다.
2. 연속으로 놓여 있는 3잔을 모두 마실 수는 없다.

효주는 될 수 있는 대로 많은 양의 포도주를 맛보기 위해서 어떤 포도주 잔을 선택해야 할지 고민하고 있다. 
1부터 n까지의 번호가 붙어 있는 n개의 포도주 잔이 순서대로 테이블 위에 놓여 있고, 각 포도주 잔에 들어있는 포도주의 양이 주어졌을 때, 
효주를 도와 가장 많은 양의 포도주를 마실 수 있도록 하는 프로그램을 작성하시오.
예를 들어 6개의 포도주 잔이 있고, 각각의 잔에 순서대로 6, 10, 13, 9, 8, 1 만큼의 포도주가 들어 있을 때, 
첫 번째, 두 번째, 네 번째, 다섯 번째 포도주 잔을 선택하면 총 포도주 양이 33으로 최대로 마실 수 있다.
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int N; cin >> N;  // 포도주 잔 개수
	int ans = 0;
	vector<int> input(N+1);
	vector<pair<int, int>> sol(N+1, make_pair(0,0));  // i번째 잔 선택 시, i-1 번째 잔 포함 여부로 경우 나눔

	cin >> input[1];
	sol[1].first = input[1];
	sol[1].second = input[1];
	ans = input[1];

	if (N > 1) {
		cin >> input[2];
		sol[2].first = input[2];  // first: i-1번째 포함 x
		sol[2].second = input[1] + input[2];  // second: i-1번째 포함
		ans = sol[2].second;
		for (int i = 3; i <= N; i++) {
			cin >> input[i];
			for (int j = 1; j <= i - 2; j++) {
				sol[i].first = max(sol[i].first, max(sol[j].first, sol[j].second));
			}
			sol[i].first += input[i];
			sol[i].second = sol[i - 1].first + input[i];
			ans = max(ans, max(sol[i].first, sol[i].second));
		}
	}
	cout << ans;
}