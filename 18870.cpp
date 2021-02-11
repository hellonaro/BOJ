#include <iostream>
#include <vector>
#include <algorithm>
#define REP(n) for(int i=0; i<n; i++)
using namespace std;

/*
수직선 위에 N개의 좌표 X1, X2, ..., Xn이 있다. 이 좌표에 좌표 압축을 적용하려고 한다.
Xi를 좌표 압축한 결과 X'i의 값은 Xi > Xj를 만족하는 서로 다른 좌표의 개수와 같아야 한다.
X1, X2, ..., Xn에 좌표 압축을 적용한 결과 X'1, X'2, ..., X'n를 출력해보자.
*/

vector<int> num;
vector<int> sorted;
int target;

int search(int start, int end) {
	int mid = (start + end) / 2;
	if (sorted[mid] == target) return mid;
	else if (sorted[mid] > target) {
		return search(start, mid - 1);
	}
	else {
		return search(mid + 1, end);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N; cin >> N;
	num.assign(N, 0);
	REP(N) {
		cin >> num[i];
	}
	sorted = num;
	sort(sorted.begin(), sorted.end());
	sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

	for (int n : num) {
		target = n;
		cout << search(0, sorted.size() - 1) << " ";
	}
}