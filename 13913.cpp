#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#define INF 999999999
using namespace std;

/*
 수빈이는 동생과 숨바꼭질을 하고 있다.
 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다.
 수빈이는 걷거나 순간이동을 할 수 있다.
 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다.
 순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.

 수빈이와 동생의 위치가 주어졌을 때,
 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.
 */

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, k; cin >> n >> k; // 언니, 동생 위치
    vector<int> course(100001, -1);
    vector<int> dist(100001, INF);
    vector<bool> visited(100001, false);
    queue<int> q;
    q.push(n);
    dist[n] = 0;
    
    while(!q.empty()){
        int cur = q.front(); q.pop();
        if(cur == k) break;
        if(visited[cur]) continue;
        visited[cur] = true;
        
        if(cur-1 >= 0){
            if(dist[cur-1] > dist[cur]+1){
                dist[cur-1] = dist[cur]+1;
                course[cur-1] = cur;
                q.push(cur-1);
            }
        }
        if(cur+1 <= 100000){
            if(dist[cur+1] > dist[cur]+1){
                dist[cur+1] = dist[cur]+1;
                course[cur+1] = cur;
                q.push(cur+1);
            }
        }
        if(cur*2 <= 100000){
            if(dist[cur*2] > dist[cur]+1){
                dist[cur*2] = dist[cur]+1;
                course[cur*2] = cur;
                q.push(cur*2);
            }
        }
    }
    
    stack<int> loca;
    loca.push(k);
    while(loca.top() != n){
        loca.push(course[loca.top()]);
    }
    cout << loca.size()-1 << endl;
    while(!loca.empty()){
        cout << loca.top() << " ";
        loca.pop();
    }
    
    return 0;
}
