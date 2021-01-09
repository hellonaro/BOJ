#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
2차원 평면 위의 점 N개가 주어진다. 좌표를 y좌표가 증가하는 순으로, 
y좌표가 같으면 x좌표가 증가하는 순서로 정렬한 다음 출력하는 프로그램을 작성하시오.
첫째 줄에 점의 개수 N (1 ≤ N ≤ 100,000)이 주어진다. 
둘째 줄부터 N개의 좌표(x, y)가 주어진다. (-100,000 ≤ x, y ≤ 100,000) 좌표는 항상 정수이고, 위치가 같은 두 점은 없다.
*/

bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.second < b.second) return true;
	else if (a.second == b.second) {
		if (a.first < b.first) return true;
		else return false;
	}
	else return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int x, y;
	vector<pair<int, int>> pos;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		pos.push_back(make_pair(x, y));
	}
	sort(pos.begin(), pos.end(), comp);

	for (int i = 0; i < pos.size(); i++) {
		cout << pos[i].first << " " << pos[i].second << "\n";
	}
}