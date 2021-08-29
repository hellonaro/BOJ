#include <iostream>
#include <vector>
using namespace std;

/*
 그래프의 정점의 집합을 둘로 분할하여,
 각 집합에 속한 정점끼리는 서로 인접하지 않도록 분할할 수 있을 때,
 그러한 그래프를 특별히 이분 그래프 (Bipartite Graph) 라 부른다.

그래프가 입력으로 주어졌을 때, 이 그래프가 이분 그래프인지 아닌지 판별하는 프로그램을 작성하시오.
 */

vector<vector<int>> graph;
vector<int> color;
bool is_bipart;

void dfs(int cur, int c){
    if(color[cur] != 0){
        if(color[cur] != c) is_bipart = false;
        return;
    }
    color[cur] = c;
    for(int next : graph[cur]){
        dfs(next, -c); // 이웃 노드는 다른 색으로 칠함
    }
}

int main(){
    int K; cin >> K; // 테스트 케이스 수
    for(int i=0; i<K; i++){
        int V, E; cin >> V >> E; // 노드, 간선 수
        graph.assign(V+1, vector<int>(0));
        for(int j=0; j<E; j++){
            int src, dst; cin >> src >> dst;
            graph[src].push_back(dst);
            graph[dst].push_back(src);
        }
        is_bipart = true;
        color.assign(V+1, 0); // 무색:0, 색1:1, 색2:-1
        
        // 그래프가 여러개인 경우의 수 고려
        for(int j=1; j<=V; j++){
            if(color[j] == 0) dfs(j, 1); // 아직 색칠 안 된 노드를 시작 노드로
        }
        if(is_bipart) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}
