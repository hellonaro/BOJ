#include <iostream>
#include <queue>
#include <set>
#define REP(n) for(int i = 0; i < n; i++)
#define MP make_pair
#define endl "\n";
using namespace std;

/*
수빈이는 동생과 숨바꼭질을 하고 있다. 
수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 
수빈이는 걷거나 순간이동을 할 수 있다. 
만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 
순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.

수빈이와 동생의 위치가 주어졌을 때, 
수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.
*/

int N, K; // 수빈이와 동생의 위치
queue<pair<int, int>> q; // 수빈이의 위치와 지난 시간
set<int> visited;

void bfs() {
	int loc = q.front().first;
	int time = q.front().second;
	q.pop();

	if (loc == K) {
		cout << time;
		return;
	}
	
	if (loc < K) {
		if (visited.find(loc + 1) == visited.end()) {
			q.push(MP(loc + 1, time + 1));
			visited.insert(loc + 1);
		}
		if (visited.find(loc * 2) == visited.end()) {
			q.push(MP(loc * 2, time + 1));
			visited.insert(loc * 2);
		}
	}
	if (visited.find(loc - 1)==visited.end()) {
		q.push(MP(loc - 1, time + 1));
		visited.insert(loc - 1);
	}
	
	bfs();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;
	q.push(MP(N, 0)); visited.insert(N);
	if (N > K) {  // 수빈이의 위치가 동생의 위치보다 크다면
		cout << N - K;
		return 0;
	}
	bfs();
}