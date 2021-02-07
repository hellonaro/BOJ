#include <iostream>
#include <queue>
#include <algorithm>
#define REP(n) for(int i = 0; i < n; i++)
#define MP make_pair
#define endl "\n";
using namespace std;

/*
N×M크기의 배열로 표현되는 미로가 있다.
미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다. 
미로의 (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오. 
한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.
*/

int N, M; // 미로의 세로와 가로
int map[101][101];
bool visited[101][101];
queue<pair<int, int>> q;

void bfs(int x, int y) {
	visited[x][y] = true;
	q.pop();
	
	if (!visited[x + 1][y] && map[x + 1][y] > 0) {
		q.push(MP(x + 1, y));
		visited[x + 1][y] = true;
		map[x + 1][y] = map[x][y] + 1;
	}
	if (!visited[x][y + 1] && map[x][y + 1] > 0) {
		q.push(MP(x, y + 1));
		visited[x][y + 1] = true;
		map[x][y + 1] = map[x][y] + 1;
	}
	if (x > 0) {
		if (!visited[x - 1][y] && map[x - 1][y] > 0) {
			q.push(MP(x - 1, y));
			visited[x - 1][y] = true;
			map[x - 1][y] = map[x][y] + 1;
		}
	}
	if (y > 0) {
		if (!visited[x][y - 1] && map[x][y - 1] > 0) {
			q.push(MP(x, y - 1));
			visited[x][y - 1] = true;
			map[x][y - 1] = map[x][y] + 1;
		}
	}
	if (q.empty()) return;
	bfs(q.front().first, q.front().second);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < M; y++) {
			char input; cin >> input;
			map[x][y] = input - 48;
			visited[x][y] = false;
		}
	}
	q.push(MP(0, 0)); bfs(0, 0);
	cout << map[N - 1][M - 1];
}