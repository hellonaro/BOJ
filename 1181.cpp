#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
알파벳 소문자로 이루어진 N개의 단어가 들어오면 아래와 같은 조건에 따라 정렬하는 프로그램을 작성하시오.
(길이가 짧은 것부터 길이가 같으면 사전 순으로)
*/

bool comp(string a, string b) {
	if (a.length() < b.length()) return true;
	else if (a.length() > b.length()) return false;
	else {
		for (int i = 0; i < a.length(); i++) {
			if (a[i] < b[i]) return true;
			else if (a[i] > b[i]) return false;
		}
		return false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	string word;
	vector<string> words;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> word;
		words.push_back(word);
	}
	sort(words.begin(), words.end(), comp);

	word = words[0];
	cout << word << "\n";
	for (int i = 1; i < words.size(); i++) {
		if (word != words[i]) {
			word = words[i];
			cout << word << "\n";
		}
	}
}