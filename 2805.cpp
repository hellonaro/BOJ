#include <iostream>
#include <map>
#include <vector>
using namespace std;

/*
상근이는 나무 M미터가 필요하다. 
근처에 나무를 구입할 곳이 모두 망해버렸기 때문에, 정부에 벌목 허가를 요청했다. 
정부는 상근이네 집 근처의 나무 한 줄에 대한 벌목 허가를 내주었고, 
상근이는 새로 구입한 목재절단기를 이용해서 나무를 구할것이다.

목재절단기는 다음과 같이 동작한다. 
먼저, 상근이는 절단기에 높이 H를 지정해야 한다. 
높이를 지정하면 톱날이 땅으로부터 H미터 위로 올라간다. 
그 다음, 한 줄에 연속해있는 나무를 모두 절단해버린다. 
따라서, 높이가 H보다 큰 나무는 H 위의 부분이 잘릴 것이고, 낮은 나무는 잘리지 않을 것이다.

예를 들어, 한 줄에 연속해있는 나무의 높이가 20, 15, 10, 17이라고 하자. 
상근이가 높이를 15로 지정했다면, 나무를 자른 뒤의 높이는 15, 15, 10, 15가 될 것이고, 
상근이는 길이가 5인 나무와 2인 나무를 들고 집에 갈 것이다. (총 7미터를 집에 들고 간다) 
절단기에 설정할 수 있는 높이는 양의 정수 또는 0이다.

상근이는 환경에 매우 관심이 많기 때문에, 나무를 필요한 만큼만 집으로 가져가려고 한다. 
이때, 적어도 M미터의 나무를 집에 가져가기 위해서 절단기에 설정할 수 있는 높이의 최댓값을 구하는 프로그램을 작성하시오.
*/

int N, M;
map<int,int> input;
map<int, int>::iterator iter;
vector<pair<int, int>> tree;

bool valid(int height) {
	long long sum = 0;
	for (pair<int, int> tree : tree) {
		if (tree.first <= height) break;
		sum += (long long)(tree.first - height) * tree.second;
	}
	if (sum >= M) return true;
	else return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int tmp; cin >> tmp;
		input[tmp]++;
	}
	long long start = 0;
	for (iter = --input.end(); iter != input.begin(); iter--) {
		tree.push_back(make_pair(iter->first, iter->second));
		start += tree.back().first*tree.back().second;
	}
	tree.push_back(make_pair(iter->first, iter->second));
	start += (long long)tree.back().first * tree.back().second;

	start -= M;
	start /= N;
	
	int height = 0;
	for (int next = start; next >= 1; next /= 2) {
		while (valid(height + next)) height += next;
	}
	cout << height;
}