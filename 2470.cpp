#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 2000000000
using namespace std;

/*
KOI 부설 과학연구소에서는 많은 종류의 산성 용액과 알칼리성 용액을 보유하고 있다. 
각 용액에는 그 용액의 특성을 나타내는 하나의 정수가 주어져있다.  
산성 용액의 특성값은 1부터 1,000,000,000까지의 양의 정수로 나타내고, 
알칼리성 용액의 특성값은 -1부터 -1,000,000,000까지의 음의 정수로 나타낸다.

같은 양의 두 용액을 혼합한 용액의 특성값은 혼합에 사용된 각 용액의 특성값의 합으로 정의한다. 
이 연구소에서는 같은 양의 두 용액을 혼합하여 특성값이 0에 가장 가까운 용액을 만들려고 한다.

산성 용액과 알칼리성 용액의 특성값이 주어졌을 때, 
이 중 두 개의 서로 다른 용액을 혼합하여 특성값이 0에 가장 가까운 용액을 만들어내는 두 용액을 찾는 프로그램을 작성하시오.
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int N; cin >> N;
	vector<int> solution(N);
	
	for (int i = 0; i < N; i++) {
		cin >> solution[i];
	}
	sort(solution.begin(), solution.end());

	int left = 0;
	int right = N - 1;

	if (solution[right] < 0) {
		cout << solution[right - 1] << " " << solution[right];
		return 0;
	}
	if (solution[left] > 0) {
		cout << solution[left] << " " << solution[left+1];
		return 0;
	}

	int sum = MAX;
	pair<int, int> result;
	bool stop_left = false;
	bool stop_right = false;
	for (; left < right ;) {
		if (abs(solution[left] + solution[right]) == 0) {
			cout << solution[left] << " " << solution[right];
		}
		if (sum > abs(solution[left] + solution[right])) {
			sum = abs(solution[left] + solution[right]);
			result.first = solution[left];
			result.second = solution[right];
		}
		if (abs(solution[left + 1] + solution[right]) < abs(solution[left] + solution[right - 1])) {
			left++;
		}
		else {
			right--;
		}
	}
	cout << result.first << " " << result.second;
}