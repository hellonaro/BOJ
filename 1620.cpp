#include <iostream>
#include <map>
#include <string>
#define endl "\n"
using namespace std;

/*
1번인 포켓몬부터 N번에 해당하는 포켓몬까지 한 줄에 하나씩 입력으로 들어와. 
그리고 M개의 문제에 대한 답을 말해줬으면 좋겠어.
입력으로 숫자가 들어왔다면 그 숫자에 해당하는 포켓몬의 이름을, 
문자가 들어왔으면 그 포켓몬의 이름에 해당하는 번호를 출력하면 돼.
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, M; cin >> N >> M; // 도감에 등록된 포켓몬 수, 맞춰야 하는 문제 수
	map<string, int> nameToNum;
	map<int, string> numToName;

	for (int i = 1; i <= N; i++) {
		string name; cin >> name;
		nameToNum[name] = i;
		numToName[i] = name;
	}

	for (int i = 0; i < M; i++) {
		string input; cin >> input;
		if (input[0] >= 65) { // 대문자로 시작한다면
			cout << nameToNum[input] << endl;
		}
		else {
			cout << numToName[stoi(input)] << endl;
		}
	}
}