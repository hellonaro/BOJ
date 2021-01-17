#include <iostream>
#include <deque>
using namespace std;

/*
자연수 n과 정수 r가 주어졌을 때, (0 <= r <= n <=1000)
이항 계수 n C r을 10007로 나눈 나머지를 구하는 프로그램을 작성하시오. 
*/

int main() {
	int n, r; cin >> n >> r;
	deque<deque<int>> ans(n+1);

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= r && j <= i; j++) {
			if (j == 0 || j == i) ans[i].push_back(1);
			else {
				int tmp = (ans[i - 1][j - 1] + ans[i - 1][j]) % 10007;
				ans[i].push_back(tmp);
			}
		}
	}
	cout << ans[n][r];
}