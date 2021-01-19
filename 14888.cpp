#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

/*
N개의 수로 이루어진 수열 A1, A2, ..., AN이 주어진다. 
또, 수와 수 사이에 끼워넣을 수 있는 N-1개의 연산자가 주어진다. 
연산자는 덧셈(+), 뺄셈(-), 곱셈(×), 나눗셈(÷)으로만 이루어져 있다.
우리는 수와 수 사이에 연산자를 하나씩 넣어서, 
수식을 하나 만들 수 있다. 이때, 주어진 수의 순서를 바꾸면 안 된다.

N개의 수와 N-1개의 연산자가 주어졌을 때, 
만들 수 있는 식의 결과가 최대인 것과 최소인 것을 구하는 프로그램을 작성하시오.
*/

int oper[4];  // +, -, *, /
deque<int> num;
deque<int> result;

void selectOper(int n, int prev) { //n번째 연산자 선택
	if (n == num.size() - 1) {
		result.push_back(prev);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (oper[i] > 0) {
			oper[i]--;
			int cur;
			if (i == 0) cur = prev + num[n + 1];
			else if (i == 1) cur = prev - num[n + 1];
			else if (i == 2) cur = prev * num[n + 1];
			else cur = prev / num[n + 1];

			selectOper(n + 1, cur);

			oper[i]++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N; cin >> N; //수의 개수

	for (int i = 0; i < N; i++) {
		int tmp; cin >> tmp;
		num.push_back(tmp);
	}
	for (int i = 0; i < 4; i++) {
		int tmp; cin >> tmp;
		oper[i] = tmp;
	}
	selectOper(0, num[0]);

	sort(result.begin(), result.end());
	cout << result.back() << endl << result.front();
}