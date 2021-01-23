#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <map>
#include <deque>
#include <string>
using namespace std;

/*
민식이는 수학학원에서 단어 수학 문제를 푸는 숙제를 받았다.
단어 수학 문제는 N개의 단어로 이루어져 있으며, 각 단어는 알파벳 대문자로만 이루어져 있다. 
이때, 각 알파벳 대문자를 0부터 9까지의 숫자 중 하나로 바꿔서 N개의 수를 합하는 문제이다.
같은 알파벳은 같은 숫자로 바꿔야 하며, 두 개 이상의 알파벳이 같은 숫자로 바뀌어지면 안 된다.
예를 들어, GCF + ACDEB를 계산한다고 할 때, 
A = 9, B = 4, C = 8, D = 6, E = 5, F = 3, G = 7로 결정한다면, 
두 수의 합은 99437이 되어서 최대가 될 것이다.
N개의 단어가 주어졌을 때, 그 수의 합을 최대로 만드는 프로그램을 작성하시오.
*/

bool desc(pair<char,int> a, pair<char,int> b) {
	if (a.second > b.second) return true;
	else return false;
}

int getScore(int n) {
	int score = 1;
	for (int i = 1; i < n; i++) {
		score *= 10;
	}
	return score;
}

int main() {
	map<char, int> score; // 문자의 점수 저장
	deque<string> word;
	int N; cin >> N;
	
	for (int i = 0; i < N; i++) {
		string tmp; cin >> tmp;
		word.push_back(tmp);
		int length = tmp.length();

		for (int j = 0; j < length; j++) {
			score[tmp[j]] += getScore(length - j);
		}
	}

	deque<pair<char, int>> num(score.begin(), score.end());  // 정렬하려고 덱으로 옮김
	sort(num.begin(), num.end(), desc) ;  // 점수 값 기준 내림차순으로 정렬

	for (int i = 0, value = 9; i < num.size(); i++, value--) {
		num[i].second = value; // 점수 가장 큰 문자부터 큰 숫자 매기기
		score[num[i].first] = num[i].second;  
	}

	int sum = 0;
	for (int i = 0; i < word.size(); i++) {
		int length = word[i].length();
		string tmp;
		for (int j = 0; j < length; j++) {
			tmp += score[word[i][j]] + 48; // 아스키코드 때문에 +48
		}
		sum += atoi(tmp.c_str());
	}
	cout << sum;
}