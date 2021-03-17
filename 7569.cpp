#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

/*
창고에 보관되는 토마토들 중에는 잘 익은 것도 있지만, 아직 익지 않은 토마토들도 있을 수 있다. 
보관 후 하루가 지나면, 익은 토마토들의 인접한 곳에 있는 익지 않은 토마토들은 익은 토마토의 영향을 받아 익게 된다. 
하나의 토마토에 인접한 곳은 위, 아래, 왼쪽, 오른쪽, 앞, 뒤 여섯 방향에 있는 토마토를 의미한다. 
대각선 방향에 있는 토마토들에게는 영향을 주지 못하며, 토마토가 혼자 저절로 익는 경우는 없다고 가정한다. 
철수는 창고에 보관된 토마토들이 며칠이 지나면 다 익게 되는지 그 최소 일수를 알고 싶어 한다.
토마토를 창고에 보관하는 격자모양의 상자들의 크기와 익은 토마토들과 익지 않은 토마토들의 정보가 주어졌을 때, 
며칠이 지나면 토마토들이 모두 익는지, 그 최소 일수를 구하는 프로그램을 작성하라. 
단, 상자의 일부 칸에는 토마토가 들어있지 않을 수도 있다.
*/

int W, D, H; //상자의 가로, 세로, 높이
int box[100][100][100];
queue<tuple<int, int, int>> ripe; // 익은 토마토들의 좌표
int raw = 0; // 익지 않은 토마토의 수
int day = 0; //토마토들이 익는데 걸리는 시간

bool isInRange(int x, int y, int z) {
	if (x < 0 || x >= W) return false;
	if (y < 0 || y >= D) return false;
	if (z < 0 || z >= H) return false;
	return true;
}

void bfs() {
	if (ripe.empty()) return;
	int x = get<0>(ripe.front());
	int y = get<1>(ripe.front());
	int z = get<2>(ripe.front());
	ripe.pop();

	if (box[x][y][z] > day) day = box[x][y][z];
	
	if (isInRange(x - 1, y, z) && box[x - 1][y][z] == 0) {
		box[x - 1][y][z] = box[x][y][z] + 1; raw--;
		ripe.push({ x - 1, y, z });
	}
	if (isInRange(x + 1, y, z) && box[x + 1][y][z] == 0) {
		box[x + 1][y][z] = box[x][y][z] + 1; raw--;
		ripe.push({ x + 1, y, z });
	}
	if (isInRange(x , y - 1, z) && box[x][y - 1][z] == 0) {
		box[x][y - 1][z] = box[x][y][z] + 1; raw--;
		ripe.push({ x, y - 1, z });
	}
	if (isInRange(x, y + 1, z) && box[x][y + 1][z] == 0) {
		box[x][y + 1][z] = box[x][y][z] + 1; raw--;
		ripe.push({ x, y + 1, z });
	}
	if (isInRange(x, y, z - 1) && box[x][y][z - 1] == 0) {
		box[x][y][z - 1] = box[x][y][z] + 1; raw--;
		ripe.push({ x , y, z - 1 });
	}
	if (isInRange(x , y, z + 1) && box[x][y][z + 1] == 0) {
		box[x][y][z + 1] = box[x][y][z] + 1; raw--;
		ripe.push({ x , y, z + 1});
	}
	bfs();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> W >> D >> H;
	for (int h = 0; h < H; h++) {
		for (int d = 0; d < D; d++) {
			for (int w = 0; w < W; w++) {
				cin >> box[w][d][h];
				if (box[w][d][h] == 0) raw++;
				else if (box[w][d][h] == 1) ripe.push({ w, d, h });
			}
		}
	}
	if (raw == 0) {
		cout << "0";
		return 0;
	}
	bfs();

	if (raw == 0) cout << day - 1;
	else cout << "-1";
	return 0;
}