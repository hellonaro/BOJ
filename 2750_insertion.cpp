#include <iostream>
using namespace std;

/*
N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.
*/

int main() {
	int N;
	cin >> N;
	int* num = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	/*insertion sort*/
	for (int i=1;i<N;i++) {
		int pivot = num[i];
		int empty_idx = i;
		for (int j = i-1; 0 <= j ; j--) {
			if (pivot < num[j]) {
				num[j + 1] = num[j];
				empty_idx = j;
			}
			else break;
		}
		num[empty_idx] = pivot;
	}

	for (int i = 0; i < N; i++) {
		cout << num[i] << endl;
	}
}