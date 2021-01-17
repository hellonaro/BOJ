#include <iostream>
#include <deque>
using namespace std;

/*
n개의 정수로 이루어진 임의의 수열이 주어진다. 
우리는 이 중 연속된 몇 개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합을 구하려고 한다. 
단, 수는 한 개 이상 선택해야 한다.
예를 들어서 10, -4, 3, 1, 5, 6, -35, 12, 21, -1 이라는 수열이 주어졌다고 하자. 
여기서 정답은 12+21인 33이 정답이 된다.
*/

int main() {
	int n; cin >> n;
	int max = -1000;
	deque<int> num;
	deque<int> result;

	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		num.push_back(tmp);
	}

	for (int i = 0; i < n; i++) {
		int sum;
		if (i == 0) {
			sum = num[0];
		}
		else {
			sum = result[i - 1] > 0 ? num[i] + result[i - 1] : num[i];
		}
		result.push_back(sum);
		if (max < result.back()) max = result.back();
	}
	cout << max;
}