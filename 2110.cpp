#include <iostream>
#include <set>
using namespace std;

/*
도현이의 집 N개가 수직선 위에 있다. 
각각의 집의 좌표는 x1, ..., xN이고, 집 여러개가 같은 좌표를 가지는 일은 없다.
도현이는 언제 어디서나 와이파이를 즐기기 위해서 집에 공유기 C개를 설치하려고 한다. 
최대한 많은 곳에서 와이파이를 사용하려고 하기 때문에, 한 집에는 공유기를 하나만 설치할 수 있고,
가장 인접한 두 공유기 사이의 거리를 가능한 크게 하여 설치하려고 한다.
C개의 공유기를 N개의 집에 적당히 설치해서, 가장 인접한 두 공유기 사이의 거리를 최대로 하는 프로그램을 작성하시오.
*/

int N, C; // 집 개수, 공유기 개수
set<int> house;  // 집 위치

bool valid(int distance) {
	int target = *house.begin();
	bool isValid = true;
	for (int i = 0; i < C; i++) {
		if (house.lower_bound(target) == house.end()) {
			isValid = false; break;
		}
		else {
			target = *house.lower_bound(target);
		}
		target += distance;
	}
	return isValid;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		int coord; cin >> coord;
		house.insert(coord);
	}
	int min = *house.begin();
	int max = *(--house.end());
	int init = (max - min) / C;
	
	int distance = 1;
	for (int next = init; next >= 1; next /= 2) {
		while (valid(distance + next)) distance += next;
	}
	cout << distance;
}
