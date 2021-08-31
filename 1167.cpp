#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<pair<int,int>>> tree;
vector<bool> visited;
vector<vector<int>> dist;

/*
 트리의 지름이란, 트리에서 임의의 두 점 사이의 거리 중 가장 긴 것을 말한다.
 트리의 지름을 구하는 프로그램을 작성하시오.
 */

void dfs(int prev, int cur, int dtc){
    visited[cur] = true;
    
    for(auto next : tree[cur]){
        if(visited[next.first]) continue;
        dfs(cur, next.first, next.second);
        // 현재 노드의 서브트리에서 가장 먼 노드 구하기
        dist[cur].push_back(dist[next.first][0]+next.second);
    }
    sort(dist[cur].begin(), dist[cur].end(), greater<int>());
}

int main(){
    int ans = 0;
    int V; cin >> V; //정점의 개수
    tree.assign(V+1,{});
    visited.assign(V+1, false);
    dist.assign(V+1,{0});
    
    for(int i=0; i<V; i++){
        int src; cin >> src;
        for(;;){
            int dst; cin >> dst;
            if(dst == -1) break;
            int dtc; cin >> dtc;
            tree[src].push_back(make_pair(dst, dtc));
        }
    }
    
    // 1을 루트 노드로 가정
    dfs(1,1,0);
    
    for(int i=1; i<=V; i++){
        if(dist[i][0]+dist[i][1] > ans){
            ans = dist[i][0]+dist[i][1];
        }
    }
   
    cout << ans;
    return 0;
}
