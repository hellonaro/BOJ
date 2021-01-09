#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

/*
온라인 저지에 가입한 사람들의 나이와 이름이 가입한 순서대로 주어진다. 
이때, 회원들을 나이가 증가하는 순으로, 나이가 같으면 먼저 가입한 사람이 앞에 오는 순서로 정렬하는 프로그램을 작성하시오
*/

bool comp(tuple<int, string, int> a, tuple<int, string, int> b) {
	if (get<0>(a) < get<0>(b)) return true;
	else if(get<0>(a) > get<0>(b)) return false;
	else {
		if (get<2>(a) < get<2>(b)) return true;
		else return false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; // 회원 수
	int age;
	string name;
	vector<tuple<int, string, int>> user; // 나이, 이름, 가입 순서

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> age >> name;
		user.push_back(make_tuple(age, name, i));
	}
	sort(user.begin(), user.end(), comp);

	for (int i = 0; i < user.size(); i++) {
		cout << get<0>(user[i]) << " " << get<1>(user[i]) << "\n";
	}
}