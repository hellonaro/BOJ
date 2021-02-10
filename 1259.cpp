#include <iostream>
#define REP(n) for(int i=0; i< n; i++)
using namespace std;

/*
어떤 단어를 뒤에서부터 읽어도 똑같다면 그 단어를 팰린드롬이라고 한다. 
'radar', 'sees'는 팰린드롬이다.
수도 팰린드롬으로 취급할 수 있다. 
수의 숫자들을 뒤에서부터 읽어도 같다면 그 수는 팰린드롬수다. 
121, 12421 등은 팰린드롬수다. 123, 1231은 뒤에서부터 읽으면 다르므로 팰린드롬수가 아니다. 또한 10도 팰린드롬수가 아닌데, 앞에 무의미한 0이 올 수 있다면 010이 되어 팰린드롬수로 취급할 수도 있지만, 
특별히 이번 문제에서는 무의미한 0이 앞에 올 수 없다고 하자.
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	for (; ; ) {
		string num; cin >> num;
		if (num == "0") return 0;
		int len = num.length();
		bool isPalin = true;
		for (int i = 0; i < len / 2; i++) {
			if (num[i] != num[len - 1 - i]) {
				isPalin = false; break;
			}
		}
		if (isPalin) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}