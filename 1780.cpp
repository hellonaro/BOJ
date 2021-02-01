#include <iostream>
#include <vector>
using namespace std;

/*
N×N크기의 행렬로 표현되는 종이가 있다. 
종이의 각 칸에는 -1, 0, 1의 세 값 중 하나가 저장되어 있다. 
우리는 이 행렬을 적절한 크기로 자르려고 하는데, 이때 다음의 규칙에 따라 자르려고 한다.
1. 만약 종이가 모두 같은 수로 되어 있다면 이 종이를 그대로 사용한다.
2. (1)이 아닌 경우에는 종이를 같은 크기의 9개의 종이로 자르고, 각각의 잘린 종이에 대해서 (1)의 과정을 반복한다.
이와 같이 종이를 잘랐을 때, -1로만 채워진 종이의 개수, 0으로만 채워진 종이의 개수, 1로만 채워진 종이의 개수를 구해내는 프로그램을 작성하시오.
*/

vector<vector<int>> paper;
int neg, zero, pos;

void cutPaper(int x, int y, int size) {
	int sum = 0;
	bool oneColor = true;
	int prev = paper[x][y];
	for (int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			if (prev != paper[x + i][y + j]) {
				oneColor = false;
			}
			sum += paper[x + i][y + j];
			prev = paper[x + i][y + j];
		}
	}
	if (sum == -(size * size)) {
		neg++;
		return;
	}
	else if (sum == 0 && oneColor) {
		zero++; 
		return;
	}
	else if (sum == size * size) {
		pos++;
		return;
	}
	else {
		cutPaper(x, y, size/3);
		cutPaper(x + (size/3), y, size/3);
		cutPaper(x + (2*size/3), y, size/3);
		cutPaper(x, y + (size/3), size/3);
		cutPaper(x + (size/3), y + (size/3), size/3);
		cutPaper(x + (2*size/3), y + (size/3), size/3);
		cutPaper(x, y + (2*size/3), size/3);
		cutPaper(x + (size/3), y + (2*size/3), size/3);
		cutPaper(x + (2*size/3), y + (2*size/3), size/3);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N; cin >> N;
	neg = 0; zero = 0; pos = 0;
	for (int i = 0; i < N; i++) {
		vector<int> line(N);
		paper.push_back(line);
		for (int j = 0; j < N; j++) {
			cin >> paper[i][j];
		}
	}
	cutPaper(0, 0, N);
	cout << neg << endl;
	cout << zero << endl;
	cout << pos << endl;
}