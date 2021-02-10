#include <iostream>
#define endl "\n"
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int L; cin >> L;
	long long ans = 0;
	for (int i = 0; i < L; i++) {
		char n; cin >> n;
		long long tmp = n - 96;
		for (int j = 0; j < i; j++) {
			tmp *= 31;
			tmp %= 1234567891;
		}
		ans += tmp;
		ans %= 1234567891;
	}
	cout << ans;
}