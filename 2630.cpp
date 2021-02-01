#include <iostream>
#include <vector>
using namespace std;

/*
주어진 종이를 일정한 규칙에 따라 잘라서 
다양한 크기를 가진 정사각형 모양의 하얀색 또는 파란색 색종이를 만들려고 한다.
입력으로 주어진 종이의 한 변의 길이 N과 각 정사각형칸의 색(하얀색 또는 파란색)이 주어질 때 
잘라진 하얀색 색종이와 파란색 색종이의 개수를 구하는 프로그램을 작성하시오.
*/

vector<vector<int>> paper;
int white, blue;

void cutPaper(int x, int y, int size) { //위치 x,y에서 size 크기로 자르는 함수
	int sum = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			sum += paper[x + i][y + j];
		}
	}
	if (sum == 0) {  // 종이 전체가 흰 색
		white++;
		return;
	}
	else if (sum == size * size) { // 종이 전체가 파란 색
		blue++;
		return;
	}
	else {
		cutPaper(x, y, size / 2);
		cutPaper(x+size/2, y, size / 2);
		cutPaper(x, y+size/2, size / 2);
		cutPaper(x+size/2, y+size/2, size / 2);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	white = 0; blue = 0;
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		vector<int> line;
		paper.push_back(line);
		for (int j = 0; j < N; j++) {
			int color; cin >> color;
			paper[i].push_back(color);
		}
	}
	cutPaper(0, 0, N);
	cout << white << endl;
	cout << blue << endl;
}