#include <iostream>
using namespace std;

/*
자연수 A를 B번 곱한 수를 알고 싶다.
단 구하려는 수가 매우 커질 수 있으므로 이를 C로 나눈 나머지를 구하는 프로그램을 작성하시오.
*/

int A, B, C;

long long getRemain(int B) {  // A를 B번 곱했을 때의 나머지 구하기
	if (B == 1) return A % C;

	long long half = getRemain(B / 2);
	long long ans = (half * half) % C;
	if (B % 2 == 1) {
		ans = (ans * A) % C;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> A >> B >> C;
	cout << getRemain(B);
}