#include <iostream>
using namespace std;

/*
LCS(Longest Common Subsequence, 최장 공통 부분 수열) 문제는 
두 수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.
예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.
주어진 두 문자열의 LCS의 길이를 출력하는 프로그램을 작성하시오.
*/

string A, B;
int result[1001][1001];

int main() {
	cin >> A >> B;
	int lenA = A.length(), lenB = B.length();
	
	bool initOne = false;
	for (int i=0; i < A.length(); i++) {
		if (initOne) {
			result[i][0] = 1;
			continue;
		}
		if (B[0] == A[i]) {
			result[i][0] = 1;
			initOne = true;
		}
	}
	initOne = false;
	for (int i = 0; i < B.length(); i++) {
		if (initOne) {
			result[0][i] = 1;
			continue;
		}
		if (A[0] == B[i]) {
			result[0][i] = 1;
			initOne = true;
		}
	}

	for (int a = 1; a < lenA; a++) {
		for (int b = 1; b < lenB; b++) {
			if (A[a] == B[b]){
				result[a][b] = result[a - 1][b - 1] + 1;
			}
			else {
				result[a][b] = max(result[a - 1][b], result[a][b - 1]);
			}
		}
	}
	cout << result[lenA - 1][lenB - 1];
}