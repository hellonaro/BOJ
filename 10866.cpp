#include <iostream>
#include <deque>
#include <string>
using namespace std;

/*
정수를 저장하는 덱(Deque)를 구현한 다음, 
입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.
명령은 총 여덟 가지이다.
- push_front X: 정수 X를 덱의 앞에 넣는다.
- push_back X: 정수 X를 덱의 뒤에 넣는다.
- pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
- pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
- size: 덱에 들어있는 정수의 개수를 출력한다.
- empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
- front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
- back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N; cin >> N;
	deque<int> num;
	
	for (int i = 0; i < N; i++) {
		string command; cin >> command;
		if (command.compare("push_front") == 0) {
			int element; cin >> element;
			num.push_front(element);
		}
		else if (command.compare("push_back") == 0) {
			int element; cin >> element;
			num.push_back(element);
		}
		else if (command.compare("pop_front") == 0) {
			if (num.empty()) cout << "-1\n";
			else {
				cout << num.front() << "\n";
				num.pop_front();
			}
		}
		else if (command.compare("pop_back") == 0) {
			if (num.empty()) cout << "-1\n";
			else {
				cout << num.back() << "\n";
				num.pop_back();
			}
		}
		else if (command.compare("size") == 0) {
			cout << num.size() << "\n";
		}
		else if (command.compare("empty") == 0) {
			if (num.empty()) cout << "1\n";
			else cout << "0\n";
		}
		else if (command.compare("front") == 0) {
			if (num.empty()) cout << "-1\n";
			else {
				cout << num.front() << "\n";
			}
		}
		else {
			if (num.empty()) cout << "-1\n";
			else {
				cout << num.back() << "\n";
			}
		}
	}
}