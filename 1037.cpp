#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

/*
양수 A가 N의 진짜 약수가 되려면, N이 A의 배수이고, A가 1과 N이 아니어야 한다.
어떤 수 N의 진짜 약수가 모두 주어질 때, N을 구하는 프로그램을 작성하시오.
*/

int main() {
	int N; cin >> N; // 진짜 약수의 개수
	deque<int> num;
	for (int i = 0; i < N; i++) {
		int tmp; cin >> tmp;
		num.push_back(tmp);
	}
	sort(num.begin(), num.end());
	cout << num.front() * num.back();
}