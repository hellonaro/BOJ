#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

/*
그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오. 
단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 
더 이상 방문할 수 있는 점이 없는 경우 종료한다. 정점 번호는 1번부터 N번까지이다.
*/

int N, M, V; // 정점의 개수, 간선의 개수, 탐색 시작할 정점의 번호
map<int, vector<int>> graph;
map<int, vector<int>>::iterator iter;
vector<bool> visited;
queue<int> q;

void dfs(int cur) {
	if (visited[cur]) return;
	cout << cur << " ";
	visited[cur] = true;
	for (int next : graph[cur]) {
		dfs(next);
	}
}
void bfs(int cur) {
	if (!q.empty()) q.pop();
	cout << cur << " ";
	visited[cur] = true;
	for (int next : graph[cur]) {
		if (!visited[next]) {
			q.push(next);
			visited[next] = true;
		}
	}
	if (q.empty()) return;
	bfs(q.front());
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M >> V;
	visited.assign(N + 1, false);
	for (int i = 0; i < M; i++) {
		int cur, next; cin >> cur >> next;
		graph[cur].push_back(next);
		graph[next].push_back(cur);
	}
	for (iter = graph.begin(); iter != graph.end(); iter++) {
		sort(iter->second.begin(), iter->second.end());
	}
	dfs(V);
	visited.assign(N + 1, false);  cout << endl;
	bfs(V);
}