#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
정확히 정의하자면 트리에 존재하는 모든 경로들 중에서 가장 긴 것의 길이를 트리의 지름이라 한다.
트리에 대한 정보가 주어졌을 때, 트리의 지름을 출력하는 프로그램을 작성하시오.
*/

int N; // 노드 수
vector<vector<int>> to_leaf; // 노드 별 리프 노드와의 거리
vector<int> diameter; // 트리의 지름
vector<vector<pair<int,int>>> tree;

void dfs(int parent) {
	if (tree[parent].empty()) {
		to_leaf[parent].push_back(0);
		return;
	}
	for (auto child : tree[parent]) {
		dfs(child.first);
		to_leaf[parent].push_back(to_leaf[child.first][0]+child.second);
	}
	sort(to_leaf[parent].begin(), to_leaf[parent].end(), greater<>());
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	tree.assign(N + 1, {});
	to_leaf.assign(N + 1, {});
	diameter.assign(N + 1, 0);

	for (int i = 0; i < N-1; i++) {
		int parent, child, depth;
		cin >> parent >> child >> depth;
		tree[parent].push_back({ child, depth });
	}
	
	dfs(1);

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < to_leaf[i].size(); j++) {
			if (j >= 2) break;
			diameter[i] += to_leaf[i][j];
		}
	}
	sort(diameter.begin(), diameter.end(), greater<>());

	cout << diameter[0];
}