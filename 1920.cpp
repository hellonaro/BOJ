#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
using namespace std;

/*
N개의 정수 A[1], A[2], …, A[N]이 주어져 있을 때, 
이 안에 X라는 정수가 존재하는지 알아내는 프로그램을 작성하시오.
*/

vector<int> A;
int target;
bool isExist;

void findNum(int start, int end) {
	if (start > end) return;
	int mid = (start + end) / 2;
	if (target < A[mid]) findNum(start, mid - 1);
	else if (target > A[mid]) findNum(mid + 1, end);
	else isExist = true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		A.push_back(num);
	}
	sort(A.begin(), A.end());
	int M; cin >> M;
	for (int i = 0; i < M; i++) {
		isExist = false;
		cin >> target;
		findNum(0, N - 1);
		if (isExist) cout << "1" << endl;
		else cout << "0" << endl;
	}
}