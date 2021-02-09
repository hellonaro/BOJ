#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define REP(n) for(int i = 0; i < n; i++)
#define MP make_pair
#define endl "\n";
using namespace std;

/*
창고에 보관되는 토마토들 중에는 잘 익은 것도 있지만, 아직 익지 않은 토마토들도 있을 수 있다. 
보관 후 하루가 지나면, 익은 토마토들의 인접한 곳에 있는 익지 않은 토마토들은 익은 토마토의 영향을 받아 익게 된다. 
하나의 토마토의 인접한 곳은 왼쪽, 오른쪽, 앞, 뒤 네 방향에 있는 토마토를 의미한다. 
대각선 방향에 있는 토마토들에게는 영향을 주지 못하며, 토마토가 혼자 저절로 익는 경우는 없다고 가정한다. 
철수는 창고에 보관된 토마토들이 며칠이 지나면 다 익게 되는지, 그 최소 일수를 알고 싶어 한다.
토마토를 창고에 보관하는 격자모양의 상자들의 크기와 익은 토마토들과 익지 않은 토마토들의 정보가 주어졌을 때, 
며칠이 지나면 토마토들이 모두 익는지, 그 최소 일수를 구하는 프로그램을 작성하라. 
단, 상자의 일부 칸에는 토마토가 들어있지 않을 수도 있다.
*/

int M, N; // 상자 가로 칸
vector<vector<int>> box; // 토마토가 담기는 상자
queue<pair<int, int>> ripe; // 익은 토마토의 위치 저장
int raw; // 익지 않은 토마토의 수
int day; // 토마토가 익는 최소 일수

void bfs() {
	if (ripe.empty()) return;
	int x = ripe.front().first;
	int y = ripe.front().second;
	ripe.pop();

	if (0 < x) {
		if (box[x - 1][y] == 0) {
			box[x - 1][y] = box[x][y] + 1; raw--;
			day = max(box[x - 1][y], day);
			ripe.push(MP(x - 1, y));
		}
	}
	if (x < N-1) {
		if (box[x + 1][y] == 0) {
			box[x + 1][y] = box[x][y] + 1; raw--;
			day = max(box[x + 1][y], day);
			ripe.push(MP(x + 1, y));
		}
	}
	if (0 < y) {
		if (box[x][y - 1] == 0) {
			box[x][y - 1] = box[x][y] + 1; raw--;
			day = max(box[x][y - 1], day);
			ripe.push(MP(x, y - 1));
		}
	}
	if (y < M-1) {
		if (box[x][y + 1] == 0) {
			box[x][y + 1] = box[x][y] + 1; raw--;
			day = max(box[x][y + 1], day);
			ripe.push(MP(x, y + 1));
		}
	}
	bfs();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> M >> N;
	box.assign(N, vector<int>(M));
	raw = 0; day = ;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < M; y++) {
			cin >> box[x][y];
			if (box[x][y] == 0) raw++;
			else if (box[x][y] == 1) {
				ripe.push(MP(x, y));
			}
		}
	}
	if (ripe.empty()) {
		cout << "-1";
		return 0;
	}
	if (raw == 0) {
		cout << "1";
		return 0;
	}
	bfs();
	if (raw > 0) cout << "-1";
	else cout << day - 1;
	return 0;
}