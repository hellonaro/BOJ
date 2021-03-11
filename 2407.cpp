#include <iostream>
#include <vector>
#define REP(n) for(int i=0; i<n; i++)
#define ll long long
#define BIG 1000000000000000000
using namespace std;

/*
nCm을 출력한다.
*/

struct BI {
	ll head;
	ll tail;
};

BI addBI(BI a, BI b) {
	ll newTail = a.tail + b.tail;
	ll newHead = a.head + b.head + newTail / BIG;
	newTail %= BIG;

	return { newHead, newTail };
}

void printBI(BI a){
	if (a.head == 0) {
		cout << a.tail;
	}
	else {
		cout << a.head;
		printf("%018lld", a.tail);
	}
}

int main() {
	int n, m; cin >> n >> m;
	vector<vector<BI>> comb(n, vector<BI>(m+1));

	comb[0][0] = { 0, 1 }; comb[1][0] = { 0, 1 }; comb[1][1] = { 0, 1 };
	for (int i = 2; i < n; i++) {
		for (int j = 0; j <= m; j++) {
			if (j == 0) comb[i][j] = { 0, 1 };
			else if (j == i) comb[i][j] = { 0, 1 };
			else comb[i][j] = addBI(comb[i - 1][j - 1], comb[i - 1][j]);
		}
	}
	printBI(addBI(comb[n - 1][m - 1], comb[n - 1][m]));
}