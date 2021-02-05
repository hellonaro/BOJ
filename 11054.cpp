#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
수열 S가 어떤 수 Sk를 기준으로 S1 < S2 < ... Sk-1 < Sk > Sk+1 > ... SN-1 > SN을 만족한다면, 그 수열을 바이토닉 수열이라고 한다.
예를 들어, {10, 20, 30, 25, 20}과 {10, 20, 30, 40}, {50, 40, 25, 10} 은 바이토닉 수열이지만,  
{1, 2, 3, 2, 1, 2, 3, 2, 1}과 {10, 20, 30, 40, 20, 30} 은 바이토닉 수열이 아니다.
수열 A가 주어졌을 때, 그 수열의 부분 수열 중 바이토닉 수열이면서 가장 긴 수열의 길이를 구하는 프로그램을 작성하시오.
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N; cin >> N;
	int ans = 1;
	vector<int> num(N);
	vector<int> inc(N, 1);
	vector<int> dec(N, 1);

	for (int i = 0; i < N; i++) {
		cin >> num[i];
		for (int j = 0; j < i; j++) {
			if (num[j] < num[i]) {
				inc[i] = max(inc[j]+1, inc[i]);
			}
		}
	}
	for (int i = N - 1; i >= 0; i--) {
		for (int j = i; j < N; j++) {
			if (num[j] < num[i]) {
				dec[i] = max(dec[j] + 1, dec[i]);
			}
		}
	}
	
	for (int i = 0; i < N; i++) {
		ans = max(ans, inc[i] + dec[i]);
	}
	cout << ans-1;
}