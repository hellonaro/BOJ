#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
using namespace std;

/*
바로 어제 최백준 조교가 방 열쇠를 주머니에 넣은 채 깜빡하고 서울로 가 버리는 황당한 상황에 직면한 조교들은, 
702호에 새로운 보안 시스템을 설치하기로 하였다. 이 보안 시스템은 열쇠가 아닌 암호로 동작하게 되어 있는 시스템이다.

암호는 서로 다른 L개의 알파벳 소문자들로 구성되며 최소 한 개의 모음(a, e, i, o, u)과 최소 두 개의 자음으로 구성되어 있다. 
또한  조교들의 성향으로 미루어 보아 암호를 이루는 알파벳이 암호에서 증가하는 순서로 배열되었을 것이라고 추측된다. 
즉, abc는 가능성이 있는 암호이지만 bac는 그렇지 않다.

새 보안 시스템에서 조교들이 암호로 사용했을 법한 문자의 종류는 C가지가 있다고 한다. 
이 알파벳을 입수한 민식, 영식 형제는 조교들의 방에 침투하기 위해 암호를 추측해 보려고 한다. 
C개의 문자들이 모두 주어졌을 때, 가능성 있는 암호들을 모두 구하는 프로그램을 작성하시오.
*/


int L, C; // 암호길이, 주어지는 문자 개수
deque<char> consonant;  // 자음
deque<char> vowel;  // 모음
deque<char> password;
deque<string> store;  // 패스워드 사전 순으로 저장
int num_conso, num_vowel;  // 자음의 개수 모음의 개수

void selectConso(int n, int start) {
	if (n > num_conso) {
		deque<char> sorted = password;
		string tmp;
		sort(sorted.begin(), sorted.end());
		for (int i = 0; i < sorted.size(); i++) {
			tmp += sorted[i];
		}
		store.push_back(tmp);
		return;
	}
	for (int i = start; i < consonant.size(); i++) {
		password.push_back(consonant[i]);
		selectConso(n + 1, i + 1);
		password.pop_back();
	}
}

void selectVowel(int n, int start){
	if (n > num_vowel) {
		selectConso(1, 0);
		return;
	}
	for (int i = start; i < vowel.size(); i++) {
		password.push_back(vowel[i]);
		selectVowel(n+1, i+1);
		password.pop_back();
	}
}

void selectPassword() {
	for (int i = 1; i <= L-2; i++) {
		num_vowel = i;
		if (i > vowel.size()) return;
		num_conso = L - i;

		password.clear();
		selectVowel(1, 0);
	}
}

bool isVowel(char c) {
	if (c == 'a') return true;
	if (c == 'e') return true;
	if (c == 'i') return true;
	if (c == 'o') return true;
	if (c == 'u') return true;

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> L >> C;  
	for (int i = 0; i < C; i++) {
		char tmp; cin >> tmp;
		if (isVowel(tmp)) vowel.push_back(tmp);
		else consonant.push_back(tmp);
	}
	selectPassword();

	sort(store.begin(), store.end());
	for (int i = 0; i < store.size(); i++) {
		cout << store[i] << "\n";
	}
}