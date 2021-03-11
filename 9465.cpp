#include <iostream>
#include <vector>
#define REP(n) for(int i=0; i<n; i++)
using namespace std;

/*
상근이의 여동생 상냥이는 문방구에서 스티커 2n개를 구매했다. 
스티커는 그림 (a)와 같이 2행 n열로 배치되어 있다. 
상냥이는 스티커를 이용해 책상을 꾸미려고 한다.
상냥이가 구매한 스티커의 품질은 매우 좋지 않다. 
스티커 한 장을 떼면, 그 스티커와 변을 공유하는 스티커는 모두 찢어져서 사용할 수 없게 된다. 
즉, 뗀 스티커의 왼쪽, 오른쪽, 위, 아래에 있는 스티커는 사용할 수 없게 된다.
모든 스티커를 붙일 수 없게된 상냥이는 각 스티커에 점수를 매기고, 
점수의 합이 최대가 되게 스티커를 떼어내려고 한다. 
먼저, 그림 (b)와 같이 각 스티커에 점수를 매겼다. 
상냥이가 뗄 수 있는 스티커의 점수의 최댓값을 구하는 프로그램을 작성하시오. 
*/

int main() {
	int T; cin >> T;
	REP(T) {
		int size; cin >> size;
		vector<vector<int>> sticker(2, vector<int>(size));
		vector<vector<int>> score(2, vector<int>(size));
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < size; j++) {
				cin >> sticker[i][j];
			}
		}
		score[0][0] = sticker[0][0];
		score[1][0] = sticker[1][0];

		if (size > 1) {
			score[0][1] = score[1][0] + sticker[0][1];
			score[1][1] = score[0][0] + sticker[1][1];
			for (int i = 2; i < size; i++) {
				score[0][i] = max(score[1][i - 1], max(score[0][i - 2], score[1][i - 2])) + sticker[0][i];
				score[1][i] = max(score[0][i - 1], max(score[0][i - 2], score[1][i - 2])) + sticker[1][i];
			}
		}
		cout << max(score[0][size - 1], score[1][size - 1]) << endl;
	}
}