#include <iostream>
#include <vector>
#define REP(n) for(int i=0; i<n; i++)
#define endl "\n"
using namespace std;

/*
루트 없는 트리가 주어진다. 
이때, 트리의 루트를 1이라고 정했을 때, 각 노드의 부모를 구하는 프로그램을 작성하시오.
*/

int N;
vector<vector<int>> tree;
vector<int> parent; // 노드 별 부모 
vector<bool> visited;

void dfs(int cur, int prev) { // (현재 노드, 현재 노드의 부모 노드)
	if (visited[cur]) return;
	visited[cur] = true;

	for (int next : tree[cur]) {
		dfs(next, cur);
	}
	parent[cur] = prev;
}

int main() {
	cin >> N;
	tree.assign(N + 1, {});
	parent.assign(N + 1, {});
	visited.assign(N + 1, false);
	
	REP(N-1) {
		int a, b; cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	dfs(1, 0);

	for (int i = 2; i <= N; i++) {
		cout << parent[i] << endl;
	}
}