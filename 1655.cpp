#include <iostream>
#include <queue>
using namespace std;

/*
수빈이는 동생에게 "가운데를 말해요" 게임을 가르쳐주고 있다. 
수빈이가 정수를 하나씩 외칠때마다 동생은 지금까지 수빈이가 말한 수 중에서 중간값을 말해야 한다. 
만약, 그동안 수빈이가 외친 수의 개수가 짝수개라면 중간에 있는 두 수 중에서 작은 수를 말해야 한다.
예를 들어 수빈이가 동생에게 1, 5, 2, 10, -99, 7, 5를 순서대로 외쳤다면
동생은 1, 1, 2, 2, 2, 2, 5를 차례대로 말해야 한다. 
수빈이가 외치는 수가 주어졌을 때, 동생이 말해야 하는 수를 구하는 프로그램을 작성하시오.
*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	priority_queue<int> below;  // 중간값 이하인 수 저장, 최대 힙
	priority_queue<int, vector<int>, greater<int>> over;  // 중간값 초과인 수 저장, 최소 힙

	int N; cin >> N;
	int num; cin >> num;
	below.push(num);
	cout << below.top() << "\n";

	for (int i = 1; i < N; i++) {
		cin >> num;
		if (num <= below.top()) {  // 현재 입력된 수가 중간값 이하라면
			below.push(num);
			if (below.size() > over.size() + 1) {
				over.push(below.top());
				below.pop();
			}
		}
		else {
			over.push(num);
			if (over.size() > below.size()) {
				below.push(over.top());
				over.pop();
			}
		}
		cout << below.top() << "\n";
	}
}