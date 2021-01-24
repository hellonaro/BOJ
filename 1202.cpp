#include <iostream>
#include <set>
using namespace std;

/*
세계적인 도둑 상덕이는 보석점을 털기로 결심했다.
상덕이가 털 보석점에는 보석이 총 N개 있다. 각 보석은 무게 Mi와 가격 Vi를 가지고 있다. 
상덕이는 가방을 K개 가지고 있고, 각 가방에 담을 수 있는 최대 무게는 Ci이다. 
가방에는 최대 한 개의 보석만 넣을 수 있다.
상덕이가 훔칠 수 있는 보석의 최대 가격을 구하는 프로그램을 작성하시오.
*/

int main() {
	long long sum = 0;
	multiset <pair<int, int>, greater<pair<int, int>>> gem;  // 보석의 가치와 무게
	multiset <pair<int, int>>::iterator g_iter;

	multiset <int> bag;
	multiset <int>::iterator b_iter;

	int N, K; cin >> N >> K;  // 보석의 개수, 가방의 개수

	for (int i = 0; i < N; i++) {
		int m, v; cin >> m >> v;
		gem.insert(make_pair(v, m));  // 가치가 key
	}

	for (int i = 0; i < K; i++) {
		int vol; cin >> vol;
		bag.insert(vol);
	}

	for (g_iter = gem.begin(); g_iter != gem.end(); g_iter++) {
		b_iter = bag.lower_bound(g_iter->second);
		if (b_iter == bag.end()) continue;
		sum += g_iter->first;
		bag.erase(b_iter);
	}
	cout << sum;
}