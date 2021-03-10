#include <iostream>
#include <vector>
#define REP(n) for(int i=0; i<n; i++)
using namespace std;

/*
이진 트리를 입력받아 
전위 순회, 중위 순회, 후위 순회한 결과를 출력하는 프로그램을 작성하시오
*/

vector<pair<int, int>> tree(27); // A는 1, Z는 26
vector<int> visited(27);

void preorder(int cur) {
	if (cur == 0 || visited[cur]) return;
	char out = cur + 64;
	cout << out; visited[cur] = true;
	preorder(tree[cur].first);
	preorder(tree[cur].second);
}

void inorder(int cur) {
	if (cur == 0 || visited[cur]) return;
	inorder(tree[cur].first);
	char out = cur + 64;
	cout << out; visited[cur] = true;
	inorder(tree[cur].second);
}

void postorder(int cur) {
	if (cur == 0 || visited[cur]) return;
	postorder(tree[cur].first);
	postorder(tree[cur].second);
	char out = cur + 64;
	cout << out; visited[cur] = true;
}

int main() {
	int N; cin >> N;
	REP(N) {
		char root, left, right;
		cin >> root >> left >> right;
		if (left != '.') tree[root - 64].first = left - 64;
		if (right != '.') tree[root - 64].second = right - 64;
	}

	visited.assign(27, false);
	preorder(1); cout << endl;

	visited.assign(27, false);
	inorder(1); cout << endl;

	visited.assign(27, false);
	postorder(1); cout << endl;
}