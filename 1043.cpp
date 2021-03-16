#include <iostream>
#include <vector>
using namespace std;

/*
지민이는 파티에 가서 이야기 하는 것을 좋아한다. 
파티에 갈 때마다, 지민이는 지민이가 가장 좋아하는 이야기를 한다. 
지민이는 그 이야기를 말할 때, 있는 그대로 진실로 말하거나 엄청나게 과장해서 말한다. 
과장해서 이야기하는 것이 훨씬 더 재미있기 때문에, 되도록이면 과장해서 이야기하려고 한다. 
하지만, 지민이는 거짓말쟁이로 알려지기는 싫어한다. 
문제는 몇몇 사람들은 그 이야기의 진실을 안다는 것이다. 
따라서 이런 사람들이 파티에 왔을 때는, 지민이는 진실을 이야기할 수 밖에 없다. 
당연히, 어떤 사람이 어떤 파티에서는 진실을 듣고, 
또다른 파티에서는 과장된 이야기를 들었을 때도 지민이는 거짓말쟁이로 알려지게 된다. 
지민이는 이런 일을 모두 피해야 한다.
사람의 수 N이 주어진다. 그리고 그 이야기의 진실을 아는 사람이 주어진다. 
그리고 각 파티에 오는 사람들의 번호가 주어진다. 
지민이는 모든 파티에 참가해야 한다. 
이때, 지민이가 거짓말쟁이로 알려지지 않으면서, 
과장된 이야기를 할 수 있는 파티 개수의 최댓값을 구하는 프로그램을 작성하시오.
*/

int people, num_party;  // 사람 수, 파티 수
vector<vector<bool>> connect;
vector<bool> status; // 진실을 알고 있는 지에 대한 여부
vector<bool> visited;

void dfs(int cur) {
	if (visited[cur]) return;
	
	visited[cur] = true;
	status[cur] = true;
	for (int next = 1; next <= people; next++){
		if (connect[cur][next]) dfs(next);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> people >> num_party;
	connect.assign(people + 1, vector<bool>(people + 1, false));
	visited.assign(people + 1, false);
	status.assign(people + 1, false);

	int n; cin >> n; // 알고 있는 사람 수
	vector<int> truth; // 진실을 알고 있는 사람의 번호
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		status[num] = true;
		truth.push_back(num);
	}

	vector<vector<int>> party(num_party);
	for (int i = 0; i < num_party; i++) {
		int p; cin >> p; // 파티 참가 인원
		int src, dst;
		for (int j = 0; j < p; j++) {
			if (j == 0) {
				cin >> src;
				party[i].push_back(src);
			}
			else {
				cin >> dst;
				party[i].push_back(dst);
				connect[src][dst] = 1;
				connect[dst][src] = 1;
			}
		}
	}
	for (int know : truth) {
		dfs(know);
	}
	int count = 0;
	for (int i = 0; i < num_party; i++) {
		bool canTell = true;
		for (int person : party[i]) {
			if (status[person]) {
				canTell = false;
				break;
			}
		}
		if (canTell) count++;
	}
	cout << count;
}