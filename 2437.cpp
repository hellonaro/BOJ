#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;


/*
하나의 양팔 저울을 이용하여 물건의 무게를 측정하려고 한다. 
이 저울의 양 팔의 끝에는 물건이나 추를 올려놓는 접시가 달려 있고, 양팔의 길이는 같다. 
또한, 저울의 한쪽에는 저울추들만 놓을 수 있고,
다른 쪽에는 무게를 측정하려는 물건만 올려놓을 수 있다.


*/
int main() {
	int measurable = 0;  // 연속적으로 측정할 수 있는 무게 중 가장 큰 무게
	deque<int> num;

	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp; cin >> tmp;
		num.push_back(tmp);
	}
	sort(num.begin(), num.end());
	
	for (int i = 0; i < num.size(); i++) {
		if (measurable + 1 >= num[i]) {
			measurable += num[i];
		}
		else {
			break;
		}
	}

	cout << measurable+1;
	return 0;
}