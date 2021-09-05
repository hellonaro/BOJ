#include <iostream>
#include <vector>
#include <queue>
#define INF 99999999
using namespace std;

/*
 방향성이 없는 그래프가 주어진다.
 세준이는 1번 정점에서 N번 정점으로 최단 거리로 이동하려고 한다.
 또한 세준이는 두 가지 조건을 만족하면서 이동하는 특정한 최단 경로를 구하고 싶은데,
 그것은 바로 임의로 주어진 두 정점은 반드시 통과해야 한다는 것이다.

 세준이는 한번 이동했던 정점은 물론, 한번 이동했던 간선도 다시 이동할 수 있다.
 하지만 반드시 최단 경로로 이동해야 한다는 사실에 주의하라.
 1번 정점에서 N번 정점으로 이동할 때, 주어진 두 정점을 반드시 거치면서 최단 경로로 이동하는 프로그램을 작성하시오.
 */

int main(){
    int n, e; cin >> n >> e; // 정점의 수 n, 간선의 수 e
    vector<pair<int, int>> graph[n+1];
    vector<int> dist(n+1, INF); dist[1] = 0;
    priority_queue<pair<int, int>> q;
    vector<bool> processed(n+1);
    
    for(int i=0; i<e; i++){
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    int v1, v2; cin >> v1 >> v2; // 반드시 지나야 하는 정점
     
    // 1에서 v1, v2까지의 최단 거리 구하기
    q.push({-dist[1], 1});
    processed[1] = true;
    while(!q.empty()){
        int src = q.top().second;
        q.pop();
        
        for(auto next : graph[src]){
            int dst = next.first;
            int w = next.second;
            if(processed[dst]) continue;
            if(dist[dst] > dist[src]+w){
                dist[dst] = dist[src]+w;
                q.push({-dist[dst], dst});
            }
        }
    }
    int one_to_v1 = dist[v1];
    int one_to_v2 = dist[v2];
    
    
    // v1에서 v2까지의 최단 거리 구하기
    dist.assign(n+1, INF); dist[v1] = 0;
    processed.assign(n+1, false);
    
    q.push({-dist[v1], v1});
    processed[v1] = true;
    while(!q.empty()){
        int src = q.top().second;
        q.pop();
        
        for(auto next : graph[src]){
            int dst = next.first;
            int w = next.second;
            if(processed[dst]) continue;
            if(dist[dst] > dist[src]+w){
                dist[dst] = dist[src]+w;
                q.push({-dist[dst], dst});
            }
        }
    }
    int v1_to_v2 = dist[v2];
    
    
    // n에서 v1, v2까지의 최단 거리 구하기
    dist.assign(n+1, INF); dist[n] = 0;
    processed.assign(n+1, false);
    
    q.push({-dist[n], n});
    processed[n] = true;
    while(!q.empty()){
        int src = q.top().second;
        q.pop();
        
        for(auto next : graph[src]){
            int dst = next.first;
            int w = next.second;
            if(processed[dst]) continue;
            if(dist[dst] > dist[src]+w){
                dist[dst] = dist[src]+w;
                q.push({-dist[dst], dst});
            }
        }
    }
    int n_to_v1 = dist[v1];
    int n_to_v2 = dist[v2];
    
    int v1_first = one_to_v1 + v1_to_v2 + n_to_v2;
    int v2_first = one_to_v2 + v1_to_v2 + n_to_v1;
    
    int ans = min(v1_first, v2_first);
    
    if(ans >= INF) ans = -1;
    cout << ans;
    return 0;
}
