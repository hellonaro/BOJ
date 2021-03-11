#include <iostream>
#include <vector>
#define REP(n) for(int i=0; i<n; i++)
#define endl "\n"
using namespace std;

/*
N×N개의 수가 N×N 크기의 표에 채워져 있다. 
(x1, y1)부터 (x2, y2)까지 합을 구하는 프로그램을 작성하시오. 
x, y)는 x행 y열을 의미한다.
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M; cin >> N >> M; // 표의 크기, 합 구하는 횟수
	vector<vector<int>> table(N+1, vector<int>(N + 1));

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int num; cin >> num;
			table[i][j] = table[i][j - 1] + num;
		}
	}

	REP(M) {
		int sum = 0;
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		for (int row = x1; row <= x2; row++) {
			sum += table[row][y2] - table[row][y1 - 1];
		}
		cout << sum << endl;
	}
}