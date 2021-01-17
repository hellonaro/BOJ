#include <iostream>
#include <deque>
using namespace std;

/*
독일 로또는 {1, 2, ..., 49}에서 수 6개를 고른다.
로또 번호를 선택하는데 사용되는 가장 유명한 전략은 49가지 수 중 k(k>6)개의 수를 골라 집합 S를 만든 다음 그 수만 가지고 번호를 선택하는 것이다.

예를 들어, k=8, S={1,2,3,5,8,13,21,34}인 경우 이 집합 S에서 수를 고를 수 있는 경우의 수는 총 28가지이다. 
([1,2,3,5,8,13], [1,2,3,5,8,21], [1,2,3,5,8,34], [1,2,3,5,13,21], ..., [3,5,8,13,21,34])

집합 S와 k가 주어졌을 때, 수를 고르는 모든 방법을 구하는 프로그램을 작성하시오.
*/

int k;
deque<int> set;
deque<int> selected;

void selectNum(int n) { // n번째 숫자 선택
	if (n == 7) {
		for (int i = 0; i < 6; i++) {
			cout << selected[i] << " ";
		}
		cout << "\n";
		return;
	}
	int prev = selected.empty() ? 0 : selected.back();
	for (int i = 0; i < k; i++) {
		if (set[i] > prev) {
			selected.push_back(set[i]);
			selectNum(n + 1);
			selected.pop_back();
		}
	}
}

int main() {
	for (; ;) {
		set.clear();
		selected.clear();
		cin >> k;
		if (k == 0) break;
		for (int i = 0; i < k; i++) {
			int num; cin >> num;
			set.push_back(num);
		}
		selectNum(1);
		cout << "\n";
	}
}