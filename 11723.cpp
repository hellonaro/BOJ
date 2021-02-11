#include <iostream>
#include <set>
#define endl "\n"
#define REP(n) for(int i=0; i<n; i++)
using namespace std;

/*
비어있는 공집합 S가 주어졌을 때, 아래 연산을 수행하는 프로그램을 작성하시오.
- add x: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
- remove x: S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
- check x: S에 x가 있으면 1을, 없으면 0을 출력한다. (1 ≤ x ≤ 20)
- toggle x: S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
- all: S를 {1, 2, ..., 20} 으로 바꾼다.
- empty: S를 공집합으로 바꾼다.
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	set<int> S;
	set<int>::iterator target;
	set<int> tmp;
	for (int num = 1; num <= 20; num++) {
		tmp.insert(num);
	}

	int M; cin >> M; // 연산의 수
	string command; int data;
	REP(M) {
		cin >> command;
		if (command == "add") {
			cin >> data;
			S.insert(data);
		}
		else if (command == "remove") {
			cin >> data;
			target = S.find(data);
			if (target != S.end()) {
				S.erase(target);
			}
		}
		else if (command == "check") {
			cin >> data;
			target = S.find(data);
			if (target != S.end()) {
				cout << "1" << endl;
			}
			else cout << "0" << endl;
		}
		else if (command == "toggle") {
			cin >> data;
			target = S.find(data);
			if (target != S.end()) {
				S.erase(target);
			}
			else S.insert(data);
		}
		else if (command == "all") {
			S = tmp;
		}
		else if (command == "empty") {
			S.clear();
		}
	}
}