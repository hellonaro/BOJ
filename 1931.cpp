#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

/*
한 개의 회의실이 있는데 이를 사용하고자 하는 N개의 회의에 대하여 회의실 사용표를 만들려고 한다.
각 회의에 대해 시작시간과 끝나는 시간이 주어져 있고, 각 회의가 겹치지 않게 하면서 회의실을 사용할 수 있는 회의의 최대 개수를 찾아보자.
단, 회의는 한번 시작하면 중간에 중단될 수 없으며 한 회의가 끝나는 것과 동시에 다음 회의가 시작될 수 있다.
회의의 시작시간과 끝나는 시간이 같을 수도 있다. 이 경우에는 시작하자마자 끝나는 것으로 생각하면 된다.
*/

bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.second < b.second) return true;
	else if (a.second == b.second) {
		if (a.first < b.first) return true;
		else return false;
	}
	else return false;
}

int main(){
	int N; cin >> N;
	int start;
	int count = 1;
	deque<pair<int, int>> session;

	for (int i = 0; i < N; i++) {
		int start, end; cin >> start >> end;
		session.push_back(make_pair(start, end));
	}
	sort(session.begin(), session.end(), comp);
	
	start = session[0].second;
	for (int i = 1; i < N; i++) {
		if (start <= session[i].first) {
			start = session[i].second;
			count++;
		}
	}
	cout << count;
}