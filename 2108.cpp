#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

/*
통계학에서 N개의 수를 대표하는 기본 통계값에는 다음과 같은 것들이 있다. 단, N은 홀수라고 가정하자.
- 산술평균 : N개의 수들의 합을 N으로 나눈 값
- 중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
- 최빈값 : N개의 수들 중 가장 많이 나타나는 값
- 범위 : N개의 수들 중 최댓값과 최솟값의 차이
N개의 수가 주어졌을 때, 네 가지 기본 통계값을 구하는 프로그램을 작성하시오
*/

int main() {
	int N;
	cin >> N;
	int* num = new int[N];
	vector<pair<int, int>> record;
	int max_idx;
	int max_count;
	vector<int> modes;

	double sum = 0;
	int mean;
	int median;
	int mode;
	int range;

	for (int i = 0; i < N; i++) {
		cin >> num[i];
		sum += num[i];
		bool exist = false;
		for (int j = 0 ; j < record.size() ; j++) {
			if (num[i] == record[j].first) {
				record[j].second++;
				exist = true;
				break;
			}
		}
		if (!exist) {
			record.push_back(make_pair(num[i], 1));
		}
	}
	sort(num, num + N);
	
	max_idx = 0;
	max_count = record[0].second;
	for (int i = 1 ; i < record.size(); i++) {
		if (record[i].second > record[max_idx].second) {
			max_idx = i;
			max_count = record[i].second;
		}
	}
	for (int i = 0; i<record.size(); i++ ) {
		if (max_count == record[i].second) {
			modes.push_back(record[i].first);
		}
	}
	sort(modes.begin(), modes.end());

	mean = round(sum / N);
	median = num[N / 2];
	mode = modes.size() == 1 ? modes[0] : modes[1];
	range = num[N - 1] - num[0];

	cout << mean << endl;
	cout << median << endl;
	cout << mode << endl;
	cout << range << endl;
}