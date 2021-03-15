#include <iostream>
#include <vector>
#define REP(i, n, m) for(int i=n; i<=m; i++)
using namespace std;

/*
2×n 직사각형을 1×2, 2×1과 2×2 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.
 */

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	vector<int> ans(n+1, 1);
	ans[1] = 1;
	
	REP(i, 2, n) {
		ans[i] = ans[i - 1] + ans[i - 2] * 2;
		ans[i] %= 10007;
	}
	
	cout << ans[n];
}