#include <iostream>
#include <algorithm>
using namespace std;

/*
N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.
첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000,000)이 주어진다. 둘째 줄부터 N개의 숫자가 주어진다. 
*/

int main() {
	int N;
	cin >> N;
	int* num = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	sort(num, num + N);
	for (int i = 0; i < N; i++) {
		cout << num[i] << "\n";
	}
}