#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

/*
절댓값 힙은 다음과 같은 연산을 지원하는 자료구조이다.
- 배열에 정수 x (x ≠ 0)를 넣는다.
- 배열에서 절댓값이 가장 작은 값을 출력하고, 그 값을 배열에서 제거한다. 
  절댓값이 가장 작은 값이 여러개일 때는, 가장 작은 수를 출력하고, 그 값을 배열에서 제거한다.

프로그램은 처음에 비어있는 배열에서 시작하게 된다.

첫째 줄에 연산의 개수 N(1 ≤ N ≤ 100,000)이 주어진다. 
다음 N개의 줄에는 연산에 대한 정보를 나타내는 정수 x가 주어진다.
만약 x가 0이 아니라면 배열에 x라는 값을 넣는(추가하는) 연산이고, 
x가 0이라면 배열에서 가장 큰 값을 출력하고 그 값을 배열에서 제거하는 경우이다.
*/

struct cmp {
	bool operator()(int a, int b) {
		if (abs(a) > abs(b)) return true;  // 절댓값이 작은 것이 우선순위가 높게
		else if (abs(a) == abs(b)) {
			if (a > b) return true;
		}
		return false;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	priority_queue<int, vector<int>, cmp> pq;  // 오름차순
	int N; cin >> N;
	
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		if (num == 0) {
			if (pq.empty()) cout << "0\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else pq.push(num);
	}
	return 0;
}