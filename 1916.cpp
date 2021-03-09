#include <iostream>
#include <vector>
#include <tuple>
#define INF 999999999
#define REP(n) for(int i=0; i<n; i++)
using namespace std;

/*
N개의 도시가 있다. 그리고 한 도시에서 출발하여 다른 도시에 도착하는 M개의 버스가 있다. 
우리는 A번째 도시에서 B번째 도시까지 가는데 드는 버스 비용을 최소화 시키려고 한다.
A번째 도시에서 B번째 도시까지 가는데 드는 최소비용을 출력하여라. 도시의 번호는 1부터 N까지이다.
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M; cin >> N >> M;
	vector<tuple<int, int, int>> city(N + 1);
	vector<int> distance(N + 1, INF);

	REP(M) {
		int src, dst, cost; cin >> src >> dst >> cost;
		city.push_back(make_tuple(src, dst, cost));
	}

	int start, end; cin >> start >> end;
	distance[start] = 0;

	/* 벨만 포드 */
	REP(N-1) {
		int prev = distance[end];
		for (auto E : city) {
			int src = get<0>(E);
			int dst = get<1>(E);
			int cost = get<2>(E);

			if (distance[dst] > distance[src] + cost) {
				distance[dst] = distance[src] + cost;
			}
		}
		// 목적지까지 가는 비용이 바뀌지 않았다면 종료 후 출력
		if (prev == distance[end] && distance[end] < INF) {
			break;
		}
	}
	cout << distance[end];
}