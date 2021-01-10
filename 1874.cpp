#include <iostream>
#include <vector>
using namespace std;

/*
1부터 n까지의 수를 스택에 넣었다가 뽑아 늘어놓음으로써, 하나의 수열을 만들 수 있다. 이때, 스택에 push하는 순서는 반드시 오름차순을 지키도록 한다고 하자. 
임의의 수열이 주어졌을 때 스택을 이용해 그 수열을 만들 수 있는지 없는지, 있다면 어떤 순서로 push와 pop 연산을 수행해야 하는지를 알아낼 수 있다. 
이를 계산하는 프로그램을 작성하라.
입력된 수열을 만들기 위해 필요한 연산을 한 줄에 한 개씩 출력한다. push연산은 +로, pop 연산은 -로 표현하도록 한다. 불가능한 경우 NO를 출력한다.
*/


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int input = 1;
	int prev, cur;
	vector<int> num;
	vector<char> log;

	cin >> n;
	for (int i = 0, prev = 0; i < n; i++) {
		cin >> cur;
		if (cur > prev) {
			if (cur < input) {
				cout << "NO";
				return 0;
			}
			for (; input <= cur; input++) {
				num.push_back(input);
				log.push_back('+');
			}
			num.pop_back();
			log.push_back('-');
		}
		else {
			for (; num.back() != cur; ) {
				num.pop_back();
				log.push_back('-');
			}
			num.pop_back();
			log.push_back('-');
		}
		prev = cur;
	}

	for (int i = 0; i < log.size(); i++) {
		cout << log[i] << "\n";
	}
}