#include <iostream>
#include <string>
#include <deque>
using namespace std;

/*
선영이는 주말에 할 일이 없어서 새로운 언어 AC를 만들었다. AC는 정수 배열에 연산을 하기 위해 만든 언어이다. 
이 언어에는 두 가지 함수 R(뒤집기)과 D(버리기)가 있다.
함수 R은 배열에 있는 숫자의 순서를 뒤집는 함수이고, D는 첫 번째 숫자를 버리는 함수이다. 
배열이 비어있는데 D를 사용한 경우에는 에러가 발생한다.
함수는 조합해서 한 번에 사용할 수 있다. 예를 들어, "AB"는 A를 수행한 다음에 바로 이어서 B를 수행하는 함수이다. 
예를 들어, "RDD"는 배열을 뒤집은 다음 처음 두 숫자를 버리는 함수이다.
배열의 초기값과 수행할 함수가 주어졌을 때, 최종 결과를 구하는 프로그램을 작성하시오.
*/

int main(){
	int T; cin >> T;
	string p;  // 함수 명령
	int n;
	deque<string> num;
	int R_count = 0;

	for (int i = 0; i < T; i++) {
		char token;
		string tmp;
		num.clear();
		cin >> p; 
		cin >> n; 
		cin >> token; // [ 버리기
		/* 파싱 */
		for( ; ; ){
			cin >> token;
			if (n == 0) break;
			if (token == ',') {
				num.push_back(tmp);
				tmp.clear();
				continue;
			}
			if (token == ']') {
				num.push_back(tmp);
				tmp.clear();
				break;
			}
			tmp.push_back(token);
		}
		/* p 수행 */
		R_count = 0;
		bool isError = false;
		for (int j = 0; j < p.length(); j++) {
			if (p[j] == 'R') R_count++;
			if (p[j] == 'D') {
				if (num.empty()) {
					isError = true;
					break;
				}
				else {
					if (R_count % 2 == 0) num.pop_front();
					else num.pop_back();
				}
			}
		}
		/* 출력 */
		if (isError) cout << "error" << endl;
		else if (num.empty()) cout << "[]" << endl;
		else {
			cout << "[";
			if (R_count % 2 == 0) {
				for (int j = 0; j < num.size()-1; j++) {
					cout << num[j] << ',';
				}
				cout << num[num.size() - 1];
			}
			else {
				for (int j = num.size() - 1; j > 0; j--) {
					cout << num[j] << ',';
				}
				cout << num[0];
			}
			cout << "]" << endl;
		}
	}
}