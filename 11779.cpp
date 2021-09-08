#include <iostream>
#include <vector>
#include <queue>
#define INF 999999999
using namespace std;

/*
 n(1≤n≤1,000)개의 도시가 있다.
 그리고 한 도시에서 출발하여 다른 도시에 도착하는 m(1≤m≤100,000)개의 버스가 있다.
 우리는 A번째 도시에서 B번째 도시까지 가는데 드는 버스 비용을 최소화 시키려고 한다.
 그러면 A번째 도시에서 B번째 도시 까지 가는데 드는 최소비용과 경로를 출력하여라.
 항상 시작점에서 도착점으로의 경로가 존재한다.
 */

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n; cin >> n;
    int m; cin >> m;
    
    vector<pair<int, int>> graph[n+1];
    int dist[n+1];
    vector<int> through[n+1];
    vector<bool> processed(n+1);
    priority_queue<pair<int ,int>> q;
    
    for(int i=0;i<m;i++){
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    
    int src, dst; cin >> src >> dst;
    for(int i=0; i<=n; i++){
        dist[i] = INF;
    }
    dist[src] = 0;
    
    
    q.push({0, src}); //  {-가중치, 목적지}
    while(!q.empty()){
        int cur = q.top().second; q.pop();
        
        if(processed[cur]) continue;
        processed[cur] = true;
    
        for(auto next : graph[cur]){
            if(dist[next.first] > dist[cur] + next.second){
                dist[next.first] = dist[cur] + next.second;
                through[next.first] = {};
                through[next.first] = through[cur];
                through[next.first].push_back(cur);
                q.push({-dist[next.first], next.first});
            }
        }
    }
    
    cout << dist[dst] << endl;
    through[dst].push_back(dst);
    cout << through[dst].size() << endl;
    for(int city : through[dst]){
        cout << city << " ";
    }
    
    return 0;
}
