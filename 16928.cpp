#include <iostream>
#include <vector>
#define INF 9999999
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<pair<int, int>> graph[101];
    for(int i=1; i<100; i++){
        for(int j=1; j<=6; j++){
            int next = i+j;
            if(next<=100) graph[i].push_back({next, 1});
        }
    }
    vector<int> dist;
    dist.assign(101, INF);
    dist[1] = 0;
    
    int N, M; cin >> N >> M;
    for(int i=0; i< N; i++){
        int src, dst; cin >> src >> dst;
        graph[src].clear();
        graph[src].push_back({dst, 0});
    }
    for(int i=0; i< M; i++){
        int src, dst; cin >> src >> dst;
        graph[src].clear();
        graph[src].push_back({dst, 0});
    }
    
    /* 벨만-포드*/
    for(int i=1; i<100; i++){
        bool updated = false;
        for(int src=1; src<100; src++){
            for(auto next : graph[src]){
                int dst = next.first, w = next.second;
                if(dist[dst] > dist[src]+w){
                    dist[dst] =  dist[src]+w;
                    updated = true;
                }
            }
        }
        if(!updated) break;
    }
    
    cout << dist[100];
    return 0;
}
