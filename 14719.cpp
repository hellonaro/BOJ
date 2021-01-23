#include <iostream>
#include <deque>
using namespace std;

/*
2차원 세계에 블록이 쌓여있다. 비가 오면 블록 사이에 빗물이 고인다.
비는 충분히 많이 온다. 고이는 빗물의 총량은 얼마일까?
*/

int main() { 
	int H, W; cin >> H >> W;
	int rain = 0;
	deque<int> block;
	int l_max, r_max;

	for (int i = 0; i < W; i++) {
		int tmp; cin >> tmp;
		block.push_back(tmp);
	}
	
	
	for (int i = 1; i < W - 1; i++) {
		l_max = 0; r_max = 0;
		for (int j = 0; j < i; j++) {
			l_max = block[j] > l_max ? block[j] : l_max;
		}
		for (int j = i + 1; j < W; j++) {
			r_max = block[j] > r_max ? block[j] : r_max;
		}

		if (block[i] < l_max && block[i] < r_max) {
			int smaller = r_max > l_max ? l_max : r_max;
			rain += smaller - block[i];
		}
	}

	cout << rain;
}