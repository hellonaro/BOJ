#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/*
두 전봇대 A와 B 사이에 하나 둘씩 전깃줄을 추가하다 보니 전깃줄이 서로 교차하는 경우가 발생하였다. 합선의 위험이 있어 이들 중 몇 개의 전깃줄을 없애 전깃줄이 교차하지 않도록 만들려고 한다.
전깃줄이 전봇대에 연결되는 위치는 전봇대 위에서부터 차례대로 번호가 매겨진다. 
전깃줄의 개수와 전깃줄들이 두 전봇대에 연결되는 위치의 번호가 주어질 때, 
남아있는 모든 전깃줄이 서로 교차하지 않게 하기 위해 없애야 하는 전깃줄의 최소 개수를 구하는 프로그램을 작성하시오.
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N; cin >> N; // 전깃줄 개수
	vector<pair<int, int>> wire(N);
	vector<int> sol(N,1);
	int ans = 1;  // 남을 수 있는 최대 전깃줄 수

	for (int i = 0; i < N; i++) {
		cin >> wire[i].first >> wire[i].second;
	}
	sort(wire.begin(), wire.end());

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (wire[j].second < wire[i].second) {
				sol[i] = max(sol[i], sol[j] + 1);
			}
		}
		ans = max(ans, sol[i]);
	}
	cout << N - ans;
}