#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n";
using namespace std;

/*
정사각형 모양의 지도가 있다. 1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다. 
철수는 이 지도를 가지고 연결된 집의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다. 
여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다. 
대각선상에 집이 있는 경우는 연결된 것이 아니다. 
지도를 입력하여 단지수를 출력하고, 
각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.
*/

int N; // 지도의 크기
int block, home; // 단지 수와 단지를 이루는 집의 수
int map[25][25];
int visited[25][25];
vector<int> store;  // 단지 별 집의 수 저장

void dfs(int x, int y) {
	if (x < 0 || N <= x) return;
	if (y < 0 || N <= y) return;
	if (visited[x][y]) return;
	if (map[x][y] == 0) return;

	visited[x][y] = true;
	home++;
	dfs(x - 1, y); dfs(x + 1, y);
	dfs(x, y - 1); dfs(x, y + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N; block = 0;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			char input; cin >> input;
			map[x][y] = input-48;
			visited[x][y] = false;
		}
	}

	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			home = 0;
			dfs(x, y);
			if (home > 0) {
				store.push_back(home);
				block++;
			}
		}
	}
	sort(store.begin(), store.end());
	cout << block << endl;
	for (int ans : store) {
		cout << ans << endl;
	}
}