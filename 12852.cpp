#include <iostream>
#include <vector>
using namespace std;

/*
정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.
- X가 3으로 나누어 떨어지면, 3으로 나눈다.
- X가 2로 나누어 떨어지면, 2로 나눈다.
- 1을 뺀다.
정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다. 
연산을 사용하는 횟수의 최솟값과 연산의 과정을 출력하시오.
*/

int main() {
	int N; cin >> N;
	vector<int> result(N + 1);

	result[1] = 0;
	for (int cur = 2; cur <= N; cur++) {
		int prev = result[cur - 1];
		if (cur % 2 == 0) prev = min(prev, result[cur / 2]);
		if (cur % 3 == 0) prev = min(prev, result[cur / 3]);
		result[cur] = prev + 1;
	}
	cout << result[N] << endl;

	for (int cur = N; cur != 1; ) {
		cout << cur << " ";
		int prev = cur - 1;
		if (cur % 2 == 0) {
			if (result[prev] > result[cur / 2]) prev = cur / 2;
		}
		if (cur % 3 == 0) {
			if (result[prev] > result[cur / 3]) prev = cur / 3;
		}
		cur = prev;
	}
	cout << "1";
}