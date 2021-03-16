#include <iostream>
#include <vector>
using namespace std;

/*
적록색약은 빨간색과 초록색의 차이를 거의 느끼지 못한다. 
따라서, 적록색약인 사람이 보는 그림은 아닌 사람이 보는 그림과는 좀 다를 수 있다.
크기가 N×N인 그리드의 각 칸에 R(빨강), G(초록), B(파랑) 중 하나를 색칠한 그림이 있다. 
그림은 몇 개의 구역으로 나뉘어져 있는데, 구역은 같은 색으로 이루어져 있다. 
또, 같은 색상이 상하좌우로 인접해 있는 경우에 두 글자는 같은 구역에 속한다.
적록색약이 아닌 사람이 봤을 때의 구역의 개수와 적록색약인 사람이 봤을 때의 구역의 수를 
공백으로 구분해 출력하는 프로그램을 작성하시오.
*/

int N; // 그리드의 크기
vector<vector<char>> greed;
vector<vector<bool>> visited;
int zone = 0;  // 구역의 개수
int volume = 0;  // 한 구역의 크기
bool isBlindness;

bool isInGreed(int x, int y) {
	if (x < 0 || x >= N) return false;
	if (y < 0 || y >= N) return false;
	return true;
}

void checkZone(int x, int y, char color) {
	if (!isInGreed(x, y)) return;
	if (visited[x][y]) return;
	if (color == 'R') {
		if (isBlindness) {
			if (greed[x][y] == 'B') return;
		}
		else {
			if (greed[x][y] != 'R') return;
		}
	}
	else if (color == 'G') {
		if (isBlindness) {
			if (greed[x][y] == 'B') return;
		}
		else {
			if (greed[x][y] != 'G') return;
		}
	}
	else {
		if (greed[x][y] != 'B') return;
	}
	visited[x][y] = true;
	volume++;
	
	checkZone(x, y - 1, color);
	checkZone(x - 1, y, color);
	checkZone(x, y + 1, color);
	checkZone(x + 1, y, color);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	greed.assign(N, vector<char>(N));
	visited.assign(N, vector<bool>(N, false));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> greed[i][j];
		}
	}
	
	isBlindness = false;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			volume = 0;
			checkZone(x, y, greed[x][y]);
			if (volume > 0) zone++;
		}
	}
	cout << zone << " ";

	zone = 0;
	visited.assign(N, vector<bool>(N, false));
	isBlindness = true;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			volume = 0;
			checkZone(x, y, greed[x][y]);
			if (volume > 0) zone++;
		}
	}
	cout << zone;
}