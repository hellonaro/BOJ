#include <iostream>
#include <vector>
#define endl "\n"
#define MAX 9999999
using namespace std;

/*
크기가 N×N인 도시가 있다. 도시는 1×1크기의 칸으로 나누어져 있다. 
도시의 각 칸은 빈 칸, 치킨집, 집 중 하나이다. 
도시의 칸은 (r, c)와 같은 형태로 나타내고, r행 c열 또는 위에서부터 r번째 칸, 왼쪽에서부터 c번째 칸을 의미한다.
r과 c는 1부터 시작한다.

이 도시에 사는 사람들은 치킨을 매우 좋아한다. 
따라서, 사람들은 "치킨 거리"라는 말을 주로 사용한다. 
치킨 거리는 집과 가장 가까운 치킨집 사이의 거리이다. 
즉, 치킨 거리는 집을 기준으로 정해지며, 각각의 집은 치킨 거리를 가지고 있다. 
도시의 치킨 거리는 모든 집의 치킨 거리의 합이다

0은 빈 칸, 1은 집, 2는 치킨집이다.
도시에 있는 치킨집 중에서 최대 M개를 고르고, 나머지 치킨집은 모두 폐업시켜야 한다. 
어떻게 고르면, 도시의 치킨 거리가 가장 작게 될지 구하는 프로그램을 작성하시오.
*/

int N, M; // 도시의 크기, 남길 치킨집의 수
vector<pair<int, int>> house; // 집의 좌표
vector<pair<int, int>> chicken; // 치킨집의 좌표
vector<pair<int, int>> remain; // 남아 있는 치킨집
int ans = MAX; // 최소가 되는 치킨 거리

int calculDistance() {
	int sum = 0;
	for (auto src : house) {
		int dis = MAX;
		for (auto dst : remain) {
			dis = min(dis, abs(src.first - dst.first) + abs(src.second - dst.second));
		}
		sum += dis;
	}
	return sum;
}

void selectChicken(int count, int start) {
	if (count > M) {
		ans = min(ans, calculDistance());
		return ;
	}
	for (int i = start; i < chicken.size() - M + count; i++) {
		remain.push_back(chicken[i]);
		selectChicken(count + 1, i + 1);
		remain.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int info; cin >> info;
			if (info == 1) house.push_back({ i, j });
			if (info == 2) chicken.push_back({ i, j });
		}
	}
	selectChicken(1, 0);
	cout << ans;
}