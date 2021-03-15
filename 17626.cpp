#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
 라그랑주는 1770년에 모든 자연수는 넷 혹은 그 이하의 제곱수의 합으로 표현할 수 있다고 증명하였다. 
 어떤 자연수는 복수의 방법으로 표현된다. 
 예를 들면, 26은 5^2과 1^2의 합이다; 또한 4^2 + 3^2 + 1^2으로 표현할 수도 있다. 
자연수 n이 주어질 때, n을 최소 개수의 제곱수 합으로 표현하는 컴퓨터 프로그램을 작성하시오.
 */

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	int root = 0;
	vector<int> ans(n + 1, 4);
	ans[0] = 0;
	for (int i = 1; i <= n; i++) {
		root = sqrt(i);
		for (int j = 1; j <= root; j++) {
			ans[i] = min(ans[i-(j*j)], ans[i]);
		}
		ans[i]++;
	}
	cout << ans[n];
}