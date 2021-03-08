#include <iostream>
#include <vector>
#include <tuple>
#define REP(n) for(int i=0; i<n; i++)
#define endl "\n"
#define INF 99999999
using namespace std;

int main() {
	int city, bus; cin >> city >> bus;// 도시의 개수, 버스 노선의 개수
	vector<long long> time(city + 1, INF); time[1] = 0; // 도시별 거리 초기화
	vector<tuple<int, int, int>> route;
	REP(bus) {
		int src, dst, t; cin >> src >> dst >> t; // 노선 출발지, 도착지, 시간
		route.push_back(make_tuple(src, dst, t));
	}
	REP(city - 1) {
		for (auto r : route) {
			if (time[get<0>(r)] == INF) continue;
			time[get<1>(r)] = min(time[get<1>(r)], time[get<0>(r)] + get<2>(r));
		}
	}
	// 음수 사이클을 찾기 위해 추가된 라운드
	for (auto r : route) {
		if (time[get<0>(r)] == INF) continue;
		if (time[get<1>(r)] > time[get<0>(r)] + get<2>(r)){ // 시간의 감소 있으면 음수 사이클 존재
			cout << "-1" << endl;
			return 0;
		}
	}

	for (int i = 2; i <= city; i++) {
		if (time[i]  == INF) {
			cout << "-1" << endl;
		}
		else cout << time[i] << endl;
	}
}