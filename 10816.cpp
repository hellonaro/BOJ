#include <iostream>
#include <map>
using namespace std;

/*
숫자 카드는 정수 하나가 적혀져 있는 카드이다. 상근이는 숫자 카드 N개를 가지고 있다. 
정수 M개가 주어졌을 때, 이 수가 적혀있는 숫자 카드를 상근이가 몇 개 가지고 있는지 구하는 프로그램을 작성하시오
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	map<int, int> num;

	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp; cin >> tmp;
		num[tmp]++;
	}
	int M; cin >> M;
	for (int i = 0; i < M; i++) {
		int tmp; cin >> tmp;
		cout << num[tmp] << " ";
	}
}