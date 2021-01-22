#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;

/*
전화번호 목록이 일관성을 유지하려면, 한 번호가 다른 번호의 접두어인 경우가 없어야 한다.
예를 들어, 전화번호 목록이 아래와 같은 경우를 생각해보자
- 긴급전화: 911
- 상근: 97 625 999
- 선영: 91 12 54 26
이 경우에 선영이에게 전화를 걸 수 있는 방법이 없다. 
전화기를 들고 선영이 번호의 처음 세 자리를 누르는 순간 바로 긴급전화가 걸리기 때문이다. 
따라서, 이 목록은 일관성이 없는 목록이다.

전화번호 목록이 주어질 때, 이 목록이 일관성이 있는지 없는지를 구하는 프로그램을 작성하시오.
*/

int main() {
	deque<string> phone_num; 
	int t, n; cin >> t;

	for (int i = 0; i < t; i++ ) {
		phone_num.clear();

		cin >> n;
		for (int j = 0; j < n; j++) {
			string tmp; cin >> tmp;
			phone_num.push_back(tmp);
		}
		sort(phone_num.begin(), phone_num.end());

		bool isMatch = false;
		string prev = phone_num[0];
		for (int j = 1; j < phone_num.size(); j++) {
			string cur = phone_num[j];
			if (prev.length() < cur.length()) {
				isMatch = true;
				for (int k = 0; k < prev.length(); k++) {
					if (prev[k] != cur[k]) {
						isMatch = false;
						break;
					}
				}
				if (isMatch) break;
			}
			prev = cur;
		}
		if (isMatch) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}