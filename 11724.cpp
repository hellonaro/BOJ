#include <iostream>
#include <vector>
#define endl "\n"
#define REP(n) for(int i=0; i<n; i++)
using namespace std;

/*
방향 없는 그래프가 주어졌을 때, 
연결 요소 (Connected Component)의 개수를 구하는 프로그램을 작성하시오.
*/

vector<vector<int>> graph;
vector<bool> visited;
bool isCompo;

void dfs(int src){
	if (visited[src]) return;
	visited[src] = true;
	isCompo = true;
	for (int dst : graph[src]) {
		dfs(dst);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, M; cin >> N >> M; // 정점의 개수, 간선의 개수
	int src, dst;
	int compo = 0;
	graph.assign(N + 1, {}); // 인덱스 0 무시
	visited.assign(N + 1, false);

	REP(M) {
		cin >> src >> dst;
		graph[src].push_back(dst);
		graph[dst].push_back(src);
	}
	for (int src = 1; src <= N; src++) {
		isCompo = false;
		dfs(src);
		if (isCompo) compo++;
	}
	cout << compo;
}