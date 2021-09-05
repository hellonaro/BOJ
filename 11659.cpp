#include <iostream>
#include <vector>
using namespace std;

/*
 수 N개가 주어졌을 때, i번째 수부터 j번째 수까지 합을 구하는 프로그램을 작성하시오.
 */

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M; cin >> N >> M;
    vector<int> sum(N+1);
    for(int i=1; i<=N; i++){
        int num; cin >> num;
        sum[i] = sum[i-1]+num;
    }
    for(int i=0; i<M; i++){
        int start, end; cin >> start >> end;
        cout << sum[end]-sum[start-1] << "\n";
    }
    
    return 0;
}
