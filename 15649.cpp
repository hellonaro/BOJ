#include <iostream>
#include <vector>
using namespace std;

/*
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
*/

int N, M;
vector<int> sequence;
bool visit[8] = { false, };

int getSequence(int n) {
	if (n == 0) {
		for (int i = 0; i < sequence.size(); i++) {
			cout << sequence[i] << " ";
		}
		cout << "\n";
		return 0;
	}
	for (int i = 0; i < N; i++) {
		if (visit[i] == false) {
			visit[i] = true;
			sequence.push_back(i + 1);
			getSequence(n - 1);
			visit[sequence.back() - 1] = false;
			sequence.pop_back();
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	getSequence(M);
}