#include <iostream>
#include <cmath>
#include <deque>
using namespace std;

/*
오늘은 스타트링크에 다니는 사람들이 모여서 축구를 해보려고 한다. 
축구는 평일 오후에 하고 의무 참석도 아니다. 
축구를 하기 위해 모인 사람은 총 N명이고 신기하게도 N은 짝수이다. 
이제 N/2명으로 이루어진 스타트 팀과 링크 팀으로 사람들을 나눠야 한다.
BOJ를 운영하는 회사 답게 사람에게 번호를 1부터 N까지로 배정했고, 아래와 같은 능력치를 조사했다. 
능력치 Sij는 i번 사람과 j번 사람이 같은 팀에 속했을 때, 팀에 더해지는 능력치이다. 
팀의 능력치는 팀에 속한 모든 쌍의 능력치 Sij의 합이다. 
Sij는 Sji와 다를 수도 있으며, i번 사람과 j번 사람이 같은 팀에 속했을 때, 
팀에 더해지는 능력치는 Sij와 Sji이다.
축구를 재미있게 하기 위해서 스타트 팀의 능력치와 링크 팀의 능력치의 차이를 최소로 하려고 한다. 
스타트 팀과 링크 팀의 능력치의 차이의 최솟값을 출력하는 프로그램을 작성하시오.
*/

int N; // 참여 인원수
int stats[20][20];
bool selected[20];
int minGap;  // 두 팀 차이의 최소값

/* My Team : 0번 선수가 속한 팀 */
void selectMyTeam(int n, int k) { // n번 이상의 선수 중 팀의 k번째 선수 고르기
	if (k == N / 2) {
		deque<int> myMem;
		deque<int> otherMem;
		int myStats = 0;
		int otherStats = 0;
		for (int i = 0; i < N; i++) {
			if (selected[i]) myMem.push_back(i);
			else otherMem.push_back(i);
		}
		for (int i = 1; i < k; i++) {
			for (int j = 0; j < i; j++) {
				myStats += stats[myMem[i]][myMem[j]] + stats[myMem[j]][myMem[i]];
				otherStats += stats[otherMem[i]][otherMem[j]] + stats[otherMem[j]][otherMem[i]];
			}
		}

		int gap = abs(myStats - otherStats);
		if (gap < minGap) minGap = gap;
		return;
	}
	for (int i = n; i < N; i++) {
		if (selected[i] == false) {
			selected[i] = true;
			selectMyTeam(i + 1, k+1);
			selected[i] = false;
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N; 
	minGap = 40000;
	for (int i = 0; i < N; i++) {
		selected[i] = false;
		for (int j = 0; j < N; j++) {
			int tmp; cin >> tmp;
			stats[i][j] = tmp;
		}
	}
	selected[0] = true;
	selectMyTeam(1, 1);
	cout << minGap;
}}
