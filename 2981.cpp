#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
트럭을 타고 이동하던 상근이는 경찰의 검문을 받게 되었다. 
경찰은 상근이가 운반하던 화물을 하나하나 모두 확인할 것이기 때문에, 검문하는데 엄청나게 오랜 시간이 걸린다.
상근이는 시간을 때우기 위해서 수학 게임을 하기로 했다.
먼저 근처에 보이는 숫자 N개를 종이에 적는다. 
그 다음, 종이에 적은 수를 M으로 나누었을 때, 나머지가 모두 같게 되는 M을 모두 찾으려고 한다. M은 1보다 커야 한다.
N개의 수가 주어졌을 때, 가능한 M을 모두 찾는 프로그램을 작성하시오.
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; cin >> N;
	int M;
	int GCF = 0; // 최대공약수
	vector<int> factor;
	int num[100];
	int gap;

	/* 인접한 수들의 차의 최대공약수를 구함 */
	cin >> num[0];
	for (int i = 1; i < N; i++) {
		cin >> num[i];
		gap = abs(num[i] - num[i - 1]);
		if (gap == 0) continue;
		if (GCF == 0) GCF = gap;
		int dividend, divisor, remainder;
		if (GCF > gap) {
			dividend = GCF;
			divisor = gap;
		}
		else if (GCF < gap) {
			dividend = gap;
			divisor = GCF;
		}
		else {
			continue;
		}
		for (; ; ) {
			remainder = dividend % divisor;
			if (remainder == 0) {
				GCF = divisor;
				break;
			}
			dividend = divisor;
			divisor = remainder;
		}
	}
	/* GCF의 약수 출력 */
	for (int i = 2; i <= sqrt(GCF); i++) {
		if (GCF % i == 0) {
			cout << i << " ";
			factor.push_back(i);
		}
	}
	for (int firstpop = true; !factor.empty(); ) {
		if (firstpop) {  // 제곱수 대비
			if (GCF / factor.back() == factor.back()) factor.pop_back();
			firstpop = false;
			continue;
		}
		cout << GCF / factor.back() << " ";
		factor.pop_back();
	}
	cout << GCF;
}