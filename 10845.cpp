#include <iostream>
#include <queue>
#define endl "\n"
#define REP(n) for(int i=0; i< n; i++)
using namespace std;

/*
정수를 저장하는 큐를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.
명령은 총 여섯 가지이다.
- push X: 정수 X를 큐에 넣는 연산이다.
- pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
- size: 큐에 들어있는 정수의 개수를 출력한다.
- empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
- front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
- back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N; cin >> N;
	queue<int> q;
	REP(N) {
		string command; cin >> command;
		if (command == "push") {
			int data; cin >> data;
			q.push(data);
		}
		else if (command == "pop") {
			if (q.empty()) cout << "-1" << endl;
			else {
				cout << q.front() << endl;
				q.pop();
			}
		}
		else if (command == "size") {
			cout << q.size() << endl;
		}
		else if (command == "empty") {
			if (q.empty()) cout << "1" << endl;
			else cout << "0" << endl;
		}
		else if (command == "front") {
			if (q.empty()) cout << "-1" << endl;
			else {
				cout << q.front() << endl;
			}
		}
		else if (command == "back") {
			if (q.empty()) cout << "-1" << endl;
			else {
				cout << q.back() << endl;
			}
		}
	}
}