#include <iostream>
#include <vector>
#include <queue>
#define REP(n) for(int i=0; i<n; i++)
#define INF 999999999
#define endl "\n"
using namespace std;

/*
방향그래프가 주어지면 주어진 시작점에서 
다른 모든 정점으로의 최단 경로를 구하는 프로그램을 작성하시오. 
단, 모든 간선의 가중치는 10 이하의 자연수이다.
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int V, E; cin >> V >> E; // 정점, 간선의 개수
	vector<vector<pair<int, int>>> graph(V + 1);
	vector<int> dist(V + 1, INF);
	vector<bool> visited(V + 1, false);
	priority_queue<pair<int, int>> know; // 알지만 방문하지 않은 노드

	int start; cin >> start;
	dist[start] = 0; 
	know.push(make_pair(0, start));

	REP(E) {
		int src, dst, dis; cin >> src >> dst >> dis;
		graph[src].push_back(make_pair(dst, dis));
	}
	
	while (!know.empty()) {
		int cur = know.top().second;
		know.pop();
		if (visited[cur] == true) continue;
		visited[cur] = true;
		
		for (auto next : graph[cur]) {
			if (visited[next.first] == true) continue;
			if (dist[next.first] > dist[cur] + next.second) {
				dist[next.first] = dist[cur] + next.second;
				know.push(make_pair(-dist[next.first], next.first));
			}
		}
	}
	
	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) cout << "INF";
		else cout << dist[i];
		cout << endl;
	}
}