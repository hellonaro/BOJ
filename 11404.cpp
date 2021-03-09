#include <iostream>
#include <vector>
#include <queue>
#define REP(n) for(int i=0; i<n; i++)
#define INF 999999999
#define endl "\n"
using namespace std;

/*
n(2 ≤ n ≤ 100)개의 도시가 있다. 
그리고 한 도시에서 출발하여 다른 도시에 도착하는 m(1 ≤ m ≤ 100,000)개의 버스가 있다. 
각 버스는 한 번 사용할 때 필요한 비용이 있다.
모든 도시의 쌍 (A, B)에 대해서 도시 A에서 B로 가는데 
필요한 비용의 최솟값을 구하는 프로그램을 작성하시오.
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int city, bus; cin >> city >> bus; // 도시의 개수, 버스의 개수
	vector<int> row(city + 1, INF);
	vector<vector<int>> graph(city + 1, row);

	REP(bus) {
		int src, dst, cost; cin >> src >> dst >> cost;
		graph[src][dst] = min(graph[src][dst], cost);
	}

	for (int mid = 1; mid <= city; mid++) {
		for (int src = 1; src <= city; src++) {
			if (src == mid) continue;
			for (int dst=1; dst <= city; dst++ ) {
				if (dst == mid) continue;
				if (src == dst) continue;
				if (graph[src][dst] > graph[src][mid] + graph[mid][dst]) {
					graph[src][dst] = graph[src][mid] + graph[mid][dst];
				}
			}
		}
	}

	for (int i = 1; i <= city; i++) {
		for (int j = 1; j <= city; j++) {
			if (graph[i][j] == INF)
				cout << "0" << " ";
			else
				cout << graph[i][j] << " ";
		}
		cout << endl;
	}
}