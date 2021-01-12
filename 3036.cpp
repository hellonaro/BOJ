#include <iostream>
using namespace std;

/*
상근이는 창고에서 링 N개를 발견했다. 
상근이는 각각의 링이 앞에 있는 링과 뒤에 있는 링과 접하도록 바닥에 내려놓았다.
상근이는 첫 번째 링을 돌리기 시작했고, 나머지 링도 같이 돌아간다는 사실을 발견했다. 
나머지 링은 첫 번째 링 보다 빠르게 돌아가기도 했고, 느리게 돌아가기도 했다. 
이렇게 링을 돌리다 보니 첫 번째 링을 한 바퀴 돌리면, 나머지 링은 몇 바퀴 도는지 궁금해졌다.
링의 반지름이 주어질 때, 
첫 번째 링을 한 바퀴 돌리면 나머지 링은 몇 바퀴 돌아가는지 구하는 프로그램을 작성하시오.
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; cin >> N;
	int first; cin >> first;
	int other;
	int dividend, divisor, remainder;

	/* 유클리드 호제법 */
	for (int i = 0; i < N - 1; i++) {
		cin >> other;
		if (first > other) {
			dividend = first;
			divisor = other;
		}
		else if (first < other) {
			dividend = other;
			divisor = first;
		}
		else {
			cout << "1/1\n";
			continue;
		}
		for (; ; ) {
			remainder = dividend % divisor;
			if (remainder == 0) {
				break;
			}
			dividend = divisor;
			divisor = remainder;
		}
		cout << first / divisor << "/" << other / divisor << "\n";
	}
}