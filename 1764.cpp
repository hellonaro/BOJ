#include <iostream>
#include <set>
#define endl "\n"
#define REP(n) for(int i=0; i<n; i++)
using namespace std;

/*
김진영이 듣도 못한 사람의 명단과, 보도 못한 사람의 명단이 주어질 때, 
듣도 보도 못한 사람의 명단을 구하는 프로그램을 작성하시오.
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	set<string> never_heard;
	set<string> never_heard_and_seen;
	int N, M; cin >> N >> M;
	int count = 0;

	REP(N) {
		string name; cin >> name;
		never_heard.insert(name);
	}
	REP(M) {
		string name; cin >> name;
		if (never_heard.find(name) != never_heard.end()) {
			never_heard_and_seen.insert(name);
			count++;
		}
	}
	cout << count << endl;
	for (string name : never_heard_and_seen) {
		cout << name << endl;
	}
}