#include <iostream>
using namespace std;

/*
정수 A를 B로 바꾸려고 한다. 가능한 연산은 다음과 같은 두 가지이다.
- 2를 곱한다.
- 1을 수의 가장 오른쪽에 추가한다.
A를 B로 바꾸는데 필요한 연산의 최솟값을 구해보자.
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int A, B; cin >> A >> B;
	int count;
	bool canMake = false;
	for (count = 2; B > 0; count++) {
		if (B % 10 == 1) {
			B /= 10;
		}
		else if (B % 2 == 0) {
			B /= 2;
		}
		else break;

		if (A == B){
			canMake = true;
			break;
		}

	}

	if (canMake) cout << count;
	else cout << "-1";
}