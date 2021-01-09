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

	/*select sort*/
	for (int i=0;i<N-1;i++) {
		int min_index = i;
		for (int j = i+1; j < N; j++) {
			if (num[min_index] > num[j]) {
				min_index = j;
			}
		}
		int tmp = num[min_index];
		num[min_index] = num[i];
		num[i] = tmp;
	}

	for (int i = 0; i < N; i++) {
		cout << num[i] << endl;
	}
}