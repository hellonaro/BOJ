#include <iostream>
#include <vector>
using namespace std;

/*
N+1개의 I와 N개의 O로 이루어져 있으면, I와 O이 교대로 나오는 문자열을 PN이라고 한다.
I와 O로만 이루어진 문자열 S와 정수 N이 주어졌을 때, 
S안에 PN이 몇 군데 포함되어 있는지 구하는 프로그램을 작성하시오.
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M; cin >> N >> M;
	vector<char> str(M);

	vector<int> save; // 연속된 Pn의 길이 저장
	int count = 0;

	cin >> str[0] >> str[1];
	for (int i = 2; i < M; i++) {
		cin >> str[i];
		if (str[i] == 'I') {
			if (str[i - 2] == 'I' && str[i - 1] == 'O') count++;
			else {
				if (count > 0) save.push_back(count);
				count = 0;
			}
		}
		else {
			if (str[i - 1] == 'O') {
				if (count > 0) save.push_back(count);
				count = 0;
			}
		}
	}
	if(count > 0)  save.push_back(count);

	int ans = 0;
	for (int len : save) {
		if (len >= N) {
			ans += len - N + 1;
		}
	}
	cout << ans;
}
