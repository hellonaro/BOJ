#include <iostream>
using namespace std;

/*
다음과 같은 재귀함수 w(a, b, c)가 있다.
------------------------------------------------------
if a <= 0 or b <= 0 or c <= 0, then w(a, b, c) returns:
	1
if a > 20 or b > 20 or c > 20, then w(a, b, c) returns:
	w(20, 20, 20)
if a < b and b < c, then w(a, b, c) returns:
	w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)
otherwise it returns:
	w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)
-------------------------------------------------------
위의 함수를 구현하는 것은 매우 쉽다. 
하지만 그대로 구현하면 값을 구하는데 매우 오랜 시간이 걸린다. (예를 들면, a=15, b=15, c=15)
a, b, c가 주어졌을 때, w(a, b, c)를 출력하는 프로그램을 작성하시오.
*/

int main() {
	int a, b, c;
	int ans[21][21][21];

	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			for (int k = 0; k < 21; k++) {
				if (i == 0 || j == 0 || k == 0) {
					ans[i][j][k] = 1;
				}
				else if (i < j && j < k) {
					ans[i][j][k] = ans[i][j][k - 1] + ans[i][j - 1][k - 1] - ans[i][j - 1][k];
				}
				else {
					ans[i][j][k] = ans[i - 1][j][k] + ans[i - 1][j - 1][k] + ans[i - 1][j][k - 1] - ans[i - 1][j - 1][k - 1];
				}
			}
		}
	}
	for (;;) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) return 0;
		cout << "w(" << a << ", " << b << ", " << c << ") = ";
		if (a < 1 || b < 1 || c < 1) {
			cout << "1\n";
		}
		else if (a > 20 || b > 20 || c > 20) {
			cout << ans[20][20][20] << "\n";
		}
		else cout << ans[a][b][c] << "\n";
	}
}