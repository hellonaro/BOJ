#include <iostream>
using namespace std;

/*
두 수가 주어졌을 때, 다음 3가지 중 어떤 관계인지 구하는 프로그램을 작성하시오.

첫 번째 숫자가 두 번째 숫자의 약수이다. -> factor
첫 번째 숫자가 두 번째 숫자의 배수이다. -> multiple
첫 번째 숫자가 두 번째 숫자의 약수와 배수 모두 아니다. -> neither
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int first, second;
	for (; ;) {
		cin >> first >> second;
		if (first == 0 || second == 0) return 0;
		if (first > second) {
			if (first % second == 0) {
				cout << "multiple\n";
				continue;
			}
		}
		else if (first < second) {
			if (second % first == 0) {
				cout << "factor\n";
				continue;
			}
		}
		cout << "neither\n";
	}
}
