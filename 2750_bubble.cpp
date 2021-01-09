#include <iostream>
using namespace std;

/*
N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.
첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000), 둘째 줄부터 N개의 숫자가 주어진다. 이 수는 절댓값이 1,000보다 작거나 같은 정수이다.
*/

int main() {
	int N;
	cin >> N;
	int* num = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	/*bubble sort*/
	for (int i = N; i > 0; i--) {
		for (int j = 0; j < i - 1; j++) {
			if (num[j] > num[j+1]) {
				int tmp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = tmp;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << num[i] <<endl;
	}
}