#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#define REP(n) for(int i=0; i<n; i++)
using namespace std;

pair<int, int> src;
pair<int, int> dst;
map <pair<int, int>, bool> conven;

bool canArrive;

int getDistance(pair<int, int> a, pair<int, int> b) {
	int gapX = abs(b.first - a.first);
	int gapY = abs(b.second - a.second);
	return gapX + gapY;
}

void dfs(pair<int, int> cur) {
	conven[cur] = true; 
	if (cur.first == dst.first && cur.second == dst.second) return;
	
	map <pair<int, int>, bool>::iterator iter;
	for (iter = conven.begin(); iter != conven.end(); iter++) {
		if (iter->second == false) {
			if (getDistance(cur, iter->first) <= 1000) {
				dfs(iter->first);
			}
		}
	}
	return;
}

int main() {
	int T; cin >> T;
	REP(T) {
		canArrive = false;
		conven.clear();
		int n; cin >> n; // 편의점 개수
		cin >> src.first >> src.second;
		REP(n) {
			int x, y; cin >> x >> y;
			conven[make_pair(x, y)] = false;
		}
		cin >> dst.first >> dst.second;
		conven[dst] = false;
		
		dfs(src);
		if (conven[dst] == true) cout << "happy";
		else cout << "sad";
		cout << endl;
	}
}