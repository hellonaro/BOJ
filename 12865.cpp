#include <iostream>
#include <algorithm>
using namespace std;

/*
준서가 여행에 필요하다고 생각하는 N개의 물건이 있다. 각 물건은 무게 W와 가치 V를 가진다.  
아직 행군을 해본 적이 없는 준서는 최대 K만큼의 무게만을 넣을 수 있는 배낭만 들고 다닐 수 있다. 
준서가 최대한 즐거운 여행을 하기 위해 배낭에 넣을 수 있는 물건들의 가치의 최댓값을 알려주자.
첫 줄에 물품의 수 N(1 ≤ N ≤ 100)과 준서가 버틸 수 있는 무게 K(1 ≤ K ≤ 100,000)가 주어진다. 
두 번째 줄부터 N개의 줄에 거쳐 각 물건의 무게 W(1 ≤ W ≤ 100,000)와 해당 물건의 가치 V(0 ≤ V ≤ 1,000)가 주어진다.
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K, W, V;
	cin >> N >> K;
	int* prev = new int[K+1];
	int* cur = new int[K+1];

	cin >> W >> V;
	for (int i = 0; i <= K; i++) {
		if (i >= W) prev[i] = V;
		else prev[i] = 0;
	}
	for (int i = 1; i < N; i++) {
		cin >> W >> V;
		for (int j = 0; j <= K; j++ ) {
			if (W > j) cur[j] = prev[j];
			else{
				/* 무게 j를 담을 때, i번째 가방을 안 넣는 경우와 넣는 경우 중 큰 값 선택 */
				cur[j] = max(prev[j], prev[j-W] + V);
			}
		}
		for (int j = 1; j <= K; j++) {
			prev[j] = cur[j];
		}
	}
	cout << cur[K];
}
