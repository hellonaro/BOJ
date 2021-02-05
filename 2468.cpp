#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
재난방재청에서는 많은 비가 내리는 장마철에 대비해서 다음과 같은 일을 계획하고 있다. 
먼저 어떤 지역의 높이 정보를 파악한 후 그 지역에 많은 비가 내렸을 때, 
물에 잠기지 않는 안전한 영역이 최대로 몇 개가 만들어 지는지를 조사하려고 한다. 
이때, 장마철에 내리는 비의 양 이하의 모든 지점은 물에 잠긴다고 가정한다.
장마철에 내리는 비의 양에 따라서 물에 잠기지 않는 안전한 영역의 개수는 다르게 된다.

어떤 지역의 높이 정보가 주어졌을 때, 
장마철에 물에 잠기지 않는 안전한 영역의 최대 개수를 계산하는 프로그램을 작성하시오.
*/

vector<vector<int>> height;
vector<vector<bool>> visited;
int N, rain, area;  // 지역 크기, 비의 양, 안전 구역의 넓이

void initVisited() {
	vector<bool> tmp(N, false);
	visited.assign(N, tmp);
}

void get_safe_zone(int x, int y) {
	if (x < 0 || x >= N) return;
	if (y < 0 || y >= N) return;
	if (visited[x][y]) return;
	if (height[x][y] <= rain) return;
	
	visited[x][y] = true; area++;
	get_safe_zone(x + 1, y);
	get_safe_zone(x - 1, y);
	get_safe_zone(x, y + 1);
	get_safe_zone(x, y - 1);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	height.assign(N, {});

	int max_h = 0, min_h = 100;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int h; cin >> h;
			height[i].push_back(h);
			max_h = max(max_h, h);
			min_h = min(min_h, h);
		}
	}

	int ans = 1;
	for (rain = min_h; rain < max_h; rain++) {
		int count = 0;
		initVisited();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				area = 0;
				get_safe_zone(i, j);
				if (area > 0) count++;
			}
		}
		ans = max(ans, count);
	}
	cout << ans;
}