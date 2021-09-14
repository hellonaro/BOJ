#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
N명의 학생들을 키 순서대로 줄을 세우려고 한다. 
각 학생의 키를 직접 재서 정렬하면 간단하겠지만, 
마땅한 방법이 없어서 두 학생의 키를 비교하는 방법을 사용하기로 하였다. 그나마도 모든 학생들을 다 비교해 본 것이 아니고, 일부 학생들의 키만을 비교해 보았다.

일부 학생들의 키를 비교한 결과가 주어졌을 때, 
줄을 세우는 프로그램을 작성하시오.
*/

vector<vector<int>> graph;
vector<bool> visited;
stack<int> ans;

void dfs(int cur) {
	if (visited[cur]) return;
	visited[cur] = true;
	for (int next : graph[cur]) {
		dfs(next);
	}
	ans.push(cur);
}

int main() {
	int N, M; cin >> N >> M;
	graph.assign(N + 1, {});
	visited.assign(N + 1, false);

	for (int i = 0; i < M; i++) {
		int small, tall; 
		cin >> small >> tall;
		graph[small].push_back(tall);
	}

	for (int cur = 1; cur <= N; cur++) {
		if (!visited[cur]) {
			dfs(cur);
		}
	}

	while (!ans.empty()) {
		cout << ans.top() << " ";
		ans.pop();
	}

	return 0;
}