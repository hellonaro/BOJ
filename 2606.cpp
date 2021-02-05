#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

/*
어느 날 1번 컴퓨터가 웜 바이러스에 걸렸다. 
컴퓨터의 수와 네트워크 상에서 서로 연결되어 있는 정보가 주어질 때, 
1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 출력하는 프로그램을 작성하시오.
*/

map<int, vector<int>> computer;
vector<bool> visited;
queue<int> q;
int ans = 0;

void getInfected(int cur) {
	if (!q.empty()) q.pop();
	for (int next : computer[cur]) {
		if (visited[next]);
		else {
			q.push(next);
			visited[next] = true;
			ans++;
		}
	}
	if (q.empty()) return;
	getInfected(q.front());
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int V; cin >> V;  // 노드 수 = 컴퓨터 수
	int E; cin >> E;  // 간선 수
	visited.assign(V+1, false);

	for (int i = 0; i < E; i++) {
		int cur, next; cin >> cur >> next;
		computer[cur].push_back(next); 
		computer[next].push_back(cur); // 무방향 그래프이므로
	}
	visited[1] = true;
	getInfected(1);
	cout << ans;
}