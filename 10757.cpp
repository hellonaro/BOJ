#include <iostream>
#include <string>
using namespace std;

/*
두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.
0 < A,B < 10의 10000제곱
*/

int main() {
	string A, B, ans;
	bool round_up = false;;

	cin >> A;
	cin >> B;

	for ( ; !B.empty() && !A.empty() ; ) {
		int tmp = (int)A.back() + (int)B.back() - 96;
		A.pop_back();
		B.pop_back();
		if (round_up) tmp++;
		round_up = tmp > 9 ? true : false;
		ans.push_back((tmp % 10) + 48);
	}
	if (!A.empty()) {
		for ( ; !A.empty() ; ) {
			int tmp = (int)A.back() - 48;
			A.pop_back();
			if (round_up) tmp++;
			round_up = tmp > 9 ? true : false;
			ans.push_back((tmp % 10) + 48);
		}
	}
	else if(!B.empty()){
		for ( ; !B.empty() ; ) {
			int tmp = (int)B.back() - 48;
			B.pop_back();
			if (round_up) tmp++;
			round_up = tmp > 9 ? true : false;
			ans.push_back((tmp % 10) + 48);
		}
	}
	if (round_up) ans.push_back('1');

	for (int i = ans.length()-1; i >= 0; i--) {
		cout << ans[i];
	}
}