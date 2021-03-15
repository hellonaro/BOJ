#include <iostream>
#include <vector>
#define REP(i, n, m) for(int i=n; i<=m; i++)
#define INF 9999999
using namespace std;

/*
케빈 베이컨의 6단계 법칙에 의하면 지구에 있는 모든 사람들은 최대 6단계 이내에서 서로 아는 사람으로 연결될 수 있다. 
케빈 베이컨 게임은 임의의 두 사람이 최소 몇 단계 만에 이어질 수 있는지 계산하는 게임이다.
BOJ 유저의 수와 친구 관계가 입력으로 주어졌을 때, 
케빈 베이컨의 수가 가장 작은 사람을 구하는 프로그램을 작성하시오.
 */

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M; cin >> N >> M;
	vector<vector<int>> graph(N+1, vector<int>(N+1, INF));
	REP(i, 1, M) {
		int src, dst; cin >> src >> dst;
		graph[src][dst] = 1;
		graph[dst][src] = 1;
	}
	REP(i, 1, N) {
		graph[i][i] = 0;
	}

	/* 플루이드-워셜 알고리즘*/
	REP(mid, 1, N) {
		REP(src, 1, N) {
			if (mid == src) continue;
			REP(dst, 1, N) {
				if (mid == dst) continue;
				if (src == dst) continue;
				if (graph[src][dst] > graph[src][mid] + graph[mid][dst]) {
					graph[src][dst] = graph[src][mid] + graph[mid][dst];
				}
			}
		}
	}

	int ans = 1;
	int min = INF;
	REP(i, 1, N) {
		int sum = 0;
		REP(j, 1, N) {
			sum += graph[i][j];
		}
		if (min > sum) {
			ans = i;
			min = sum;
		}
	}
	cout << ans;
}