#include <iostream>
using namespace std;

/*
N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.
첫째 줄에 수의 개수 N(1 ≤ N ≤ 10,000,000)이 주어진다. 
둘째 줄부터 N개의 숫자가 주어진다. 이 수는 10,000보다 작거나 같은 자연수이다.
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	int* record = new int[10000];
	int num;

	for(int i=0 ; i<10000 ; i++){
		record[i] = 0;
	}
	for(int i=0 ; i<N ; i++) {
		cin >> num;
		record[num - 1]++;
	}
	for (int i = 0 ; i<10000 ; i++) {
		for (int j = 0; j < record[i]; j++) {
			cout << i + 1 << "\n";
		}
	}
}