#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int D(int num){
    int ans = (num*2)%10000;
    return ans;
}
int S(int num){
    int ans = num - 1;
    if(ans < 0) ans = 9999;
    return ans;
}
int L(int num){
    int head = num / 1000;
    int tail = num % 1000;
    int ans = tail * 10 + head;
    return ans;
    
}
int R(int num){
    int tail = num % 10;
    int head = num / 10;
    int ans = 1000 * tail + head;
    return ans;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T; cin >> T;
    for(int i=0; i<T; i++){
        int a, b; cin >> a >> b;
        queue<int> q;
        vector<string> dist(10000);
        
        q.push(a);
        while(!q.empty()){
            int num = q.front(); q.pop();
            if(num == b) break;
            if(dist[D(num)] == "" && num != D(num)) {
                q.push(D(num));
                dist[D(num)] = dist[num] + "D";
            }
            if(dist[S(num)] == "" && num != S(num) ){
                q.push(S(num));
                dist[S(num)] = dist[num] + "S";
            }
            if(dist[L(num)] == "" && num != L(num)){
                q.push(L(num));
                dist[L(num)] = dist[num] + "L";
            }
            if(dist[R(num)] == "" && num != R(num)){
                q.push(R(num));
                dist[R(num)] = dist[num] + "R";
            }
        }
        cout << dist[b] << "\n";
    }
    
    return 0;
}
