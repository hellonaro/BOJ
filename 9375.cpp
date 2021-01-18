#include <iostream>
#include <map>
#include <string>
using namespace std;

/*
해빈이는 패션에 매우 민감해서 한번 입었던 옷들의 조합을 절대 다시 입지 않는다. 
예를 들어 오늘 해빈이가 안경, 코트, 상의, 신발을 입었다면, 다음날은 바지를 추가로 입거나 안경대신 렌즈를 착용하거나 해야한다. 
해빈이가 가진 의상들이 주어졌을때 과연 해빈이는 알몸이 아닌 상태로 며칠동안 밖에 돌아다닐 수 있을까?
*/

int main() {
	int T; cin >> T; // 테스트 케이스 수
	int n; // 의상 수
	string name, type; // 옷 이름과 종류
	int ans;

	for (int i = 0; i < T; i++) {
		cin >> n;
		ans = 1;
		map<string, int> clothes;  // 옷 종류와 개수
		map<string, int>::iterator iter;
		for (int j = 0; j < n; j++) {
			cin >> name >> type;
			if (clothes.find(type) == clothes.end()) { // 해당 키가 맵에 존재하지 않는다면
				clothes[type] = 2;  // 옷 선택하는 경우 or 선택하지 않는 경우
			}
			else { // 존재한다면 해당 종류 옷 개수 추가
				clothes[type]++;
			}
		}
		for (iter = clothes.begin(); iter != clothes.end(); iter++) {
			ans *= iter->second;
		}
		cout << ans - 1 << endl;
	}
}