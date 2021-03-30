#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
using namespace std;

/*
N개의 자연수와 자연수 M이 주어졌을 때, N개의 자연수 중에서 M개를 고른 수열을 모두 구하는 프로그램을 작성하시오. 
N개의 자연수는 모두 다른 수이다.
*/

int N, M;
vector<int> nums;
vector<bool> visited;
vector<int> prt;

void printSeq(int count) {
	if (count > M) {
		for (int num : prt) {
			cout << num << " ";
		}
		cout << endl;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			prt.push_back(nums[i]); visited[i] = true;
			printSeq(count + 1);
			prt.pop_back(); visited[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	 cin >> N >> M; // N개의 자연수 중에 M개를 고른 수열
	 for (int i = 0; i < N; i++) {
		 int tmp; cin >> tmp;
		 nums.push_back(tmp);
	 }
	 sort(nums.begin(), nums.end());
	 visited.assign(N, false);
	 printSeq(1);
}