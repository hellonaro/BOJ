#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.
예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 
가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int N; cin >> N;
	vector<int> num(N);
	vector<int> lis(N, 1);  // i번째 원소 포함했을 때 증가하는 수열
	int ans = 1;

	cin >> num[0];
	for (int i = 1; i < N; i++) {
		cin >> num[i];
		for (int j = 0; j < i; j++) {
			if (num[i] > num[j]) {
				lis[i] = max(lis[i], lis[j]+1);
			}
		}
		ans = max(ans, lis[i]);
	}
	cout << ans;
}