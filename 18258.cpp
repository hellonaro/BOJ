#include <iostream>
#include <queue>
#include <string>
using namespace std;

/*
정수를 저장하는 큐를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.
명령은 총 여섯 가지이다.
- push X: 정수 X를 큐에 넣는 연산이다.
- pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
- size: 큐에 들어있는 정수의 개수를 출력한다.
- empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
- front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
- back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; cin >> N;
	queue<int> num;
	for (int i = 0; i < N; i++) {
		string command; cin >> command;
		if (command.compare("push") == 0) { // command가 push와 같다면 
			int n; cin >> n;
			num.push(n);
		}
		else if(command.compare("pop") == 0) { // command가 push와 같다면 
			if (!num.empty()) {
				cout << num.front() << "\n";
				num.pop();
			}
			else cout << "-1\n";
		}
		else if (command.compare("size") == 0) { // command가 push와 같다면 
			cout << num.size() << "\n";
		}
		else if (command.compare("empty") == 0) { // command가 push와 같다면 
			if (num.empty()) cout << "1\n";
			else cout << "0\n";
		}
		else if (command.compare("front") == 0) { // command가 push와 같다면 
			if (num.empty()) cout << "-1\n";
			else cout << num.front() << "\n";
		}
		else{
			if (num.empty()) cout << "-1\n";
			else cout << num.back() << "\n";
		}
	}
}