#include <iostream>
#include <set>
#define endl "\n"
#define REP(n) for(int i=0; i<n; i++)
using namespace std;

/*
이중 우선순위 큐(dual priority queue)는 전형적인 우선순위 큐처럼 데이터를 삽입, 삭제할 수 있는 자료 구조이다. 
전형적인 큐와의 차이점은 데이터를 삭제할 때 연산(operation) 명령에 따라 우선순위가 가장 높은 데이터 또는 가장 낮은 데이터 중 하나를 삭제하는 점이다. 
이중 우선순위 큐를 위해선 두 가지 연산이 사용되는데, 하나는 데이터를 삽입하는 연산이고 다른 하나는 데이터를 삭제하는 연산이다. 
데이터를 삭제하는 연산은 또 두 가지로 구분되는데 하나는 우선순위가 가장 높은 것을 삭제하기 위한 것이고 다른 하나는 우선순위가 가장 낮은 것을 삭제하기 위한 것이다.

정수만 저장하는 이중 우선순위 큐 Q가 있다고 가정하자. 
Q에 저장된 각 정수의 값 자체를 우선순위라고 간주하자.
Q에 적용될 일련의 연산이 주어질 때 이를 처리한 후 최종적으로 Q에 저장된 데이터 중 최댓값과 최솟값을 출력하는 프로그램을 작성하라.
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T; cin >> T; // 테스트 케이스 수
	int k; // 연산 개수
	multiset<int> data;
	multiset<int>::iterator max;
	REP(T) {
		data.clear();
		cin >> k;
		REP(k) {
			char command; cin >> command;
			int num; cin >> num;

			if (command == 'I') { // 데이터 삽입하는 경우
				data.insert(num);
			}
			else {
				if (data.empty()) continue;
				else if (num == -1) {  // 최솟값 삭제
					data.erase(data.begin());
				}
				else {  // 최댓값 삭제
					max = --data.end();
					data.erase(max);
				}
			}
		}
		if (data.empty()) cout << "EMPTY" << endl;
		else {
			max = --data.end();
			cout << *max << " " << *data.begin() << endl;
		}
	}
}