#include <iostream>
#include <vector>
#include <algorithm>
#define REP(n) for(int i = 0; i < n; i++)
#define endl "\n";
using namespace std;

/*
차세대 영농인 한나는 강원도 고랭지에서 유기농 배추를 재배하기로 하였다. 
농약을 쓰지 않고 배추를 재배하려면 배추를 해충으로부터 보호하는 것이 중요하기 때문에, 
한나는 해충 방지에 효과적인 배추흰지렁이를 구입하기로 결심한다. 
이 지렁이는 배추근처에 서식하며 해충을 잡아 먹음으로써 배추를 보호한다. 
특히, 어떤 배추에 배추흰지렁이가 한 마리라도 살고 있으면 이 지렁이는 인접한 다른 배추로 이동할 수 있어, 
그 배추들 역시 해충으로부터 보호받을 수 있다.
(한 배추의 상하좌우 네 방향에 다른 배추가 위치한 경우에 서로 인접해있다고 간주한다)

한나가 배추를 재배하는 땅은 고르지 못해서 배추를 군데군데 심어놓았다. 
배추들이 모여있는 곳에는 배추흰지렁이가 한 마리만 있으면 되므로 
서로 인접해있는 배추들이 몇 군데에 퍼져있는지 조사하면 
총 몇 마리의 지렁이가 필요한지 알 수 있다.
*/

int M, N, cabbage; // 밭의 가로, 세로, 배추 수
int worm, ans;
int field[50][50];
bool visited[50][50];
vector<int> store;  // 단지 별 집의 수 저장

void dfs(int x, int y) {
	if (x < 0 || M <= x) return;
	if (y < 0 || N <= y) return;
	if (visited[x][y]) return;
	if (field[x][y] == 0) return;

	visited[x][y] = true; worm++;
	dfs(x - 1, y); dfs(x + 1, y);
	dfs(x, y - 1); dfs(x, y + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int T; cin >> T; //테스트 케이스 수
	REP(T) {
		ans = 0;
		cin >> M >> N >> cabbage;
		for (int x = 0; x < M; x++) {
			for (int y = 0; y < N; y++) {
				field[x][y] = 0;
				visited[x][y] = false;
			}
		}
		REP(cabbage) {
			int x, y; cin >> x >> y;
			field[x][y] = 1;
		}
		for (int x = 0; x < M; x++) {
			for (int y = 0; y < N; y++) {
				worm = 0;
				dfs(x, y);
				if (worm > 0) ans++;
			}
		}
		cout << ans << endl;
	}
}