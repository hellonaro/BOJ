#include <iostream>
#include <vector>
using namespace std;

/*
상담원으로 일하고 있는 백준이는 퇴사를 하려고 한다.
오늘부터 N+1일째 되는 날 퇴사를 하기 위해서, 남은 N일 동안 최대한 많은 수익을 얻으려고 한다.
상담은 상담을 완료하는데 걸리는 기간 T와 상담을 했을 때 받을 수 있는 금액 P로 이루어져 있다.
상담을 적절히 했을 때, 백준이가 얻을 수 있는 최대 수익을 구하는 프로그램을 작성하시오.
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int max = 0;
	int result[15];
	vector<pair<int, int>> consulting;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int time, pay;
		cin >> time;
		cin >> pay;
		consulting.push_back(make_pair(time, pay));
		result[i] = i + time <= n ? pay : 0;
	}
	/* dynamic programming */
	for (int i = 1; i < n; i++) {
		int max = 0;
		for (int j = 0; j < i; j++){
			if (j + consulting[j].first <= i) {
				if (max < result[j]) max = result[j];
			}
		}
		result[i] += max;
	}
	max = 0;
	for (int i = 0; i < n; i++) {
		if (max < result[i]) max = result[i];
	}
	cout << max;
}	