#include <iostream>
#include <vector>
using namespace std;

/*
크기가 N인 수열 A = A1, A2, ..., AN이 있다. 수열의 각 원소 Ai에 대해서 오큰수 NGE(i)를 구하려고 한다. 
Ai의 오큰수는 오른쪽에 있으면서 Ai보다 큰 수 중에서 가장 왼쪽에 있는 수를 의미한다. 그러한 수가 없는 경우에 오큰수는 -1이다.
예를 들어, A = [3, 5, 2, 7]인 경우 NGE(1) = 5, NGE(2) = 7, NGE(3) = 7, NGE(4) = -1이다.
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000,000)이 주어진다. 둘째에 수열 A의 원소 A1, A2, ..., AN (1 ≤ Ai ≤ 1,000,000)이 주어진다.
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	pair<int, int> prev;
	pair<int, int> cur;
	int tmp;
	int* result;
	vector<pair<int,int>> store;  // NGE 모르는 수들 보관

	cin >> n;
	cin >> tmp;
	if (n == 1) {
		cout << "-1";
		return 0;
	}
	result = new int[n];
	prev = make_pair(0, tmp);
	for (int i = 1; i < n; i++) {
		cin >> tmp;
		cur = make_pair(i, tmp);
		if (prev.second < cur.second) {
			result[i - 1] = cur.second;
			for (; !store.empty() && store.back().second < cur.second;) {
				result[store.back().first] = cur.second;
				store.pop_back();
			}
		}
		else {
			store.push_back(prev);
		}
		if (i == n - 1) {
			result[cur.first] = -1;
			break;
		}
		prev = cur;
	}
	for (int i = 0; i < store.size(); i++) {
		result[store[i].first] = -1;
	}
	for (int i = 0; i < n; i++) {
		cout << result[i] << " ";
	}
}