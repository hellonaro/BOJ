#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
 그래프는 정점과 간선으로 이루어져 있다.
 두 정점 사이에 경로가 있다면, 두 정점은 연결되어 있다고 한다.
 연결 요소는 모든 정점이 서로 연결되어 있는 정점의 부분집합이다.
 그래프는 하나 또는 그 이상의 연결 요소로 이루어져 있다.

 트리는 사이클이 없는 연결 요소이다.
 트리에는 여러 성질이 있다.
 예를 들어, 트리는 정점이 n개, 간선이 n-1개 있다.
 또, 임의의 두 정점에 대해서 경로가 유일하다.

 그래프가 주어졌을 때, 트리의 개수를 세는 프로그램을 작성하시오.
 */

bool is_graph;
vector<vector<int>> graph;
vector<map<int, int>> edge; // 같은 간선이 등장한 횟수가 value
vector<bool> visited;

void dfs(int prev, int cur){
    if(visited[cur]) {
        /* 방문했는데 돌아갈 간선이 남아있다면 사이클 존재*/
        if(prev < cur && edge[prev][cur] > 0){
            is_graph = true;
        }
        else if(cur <= prev && edge[cur][prev] > 0){
            is_graph = true;
        }
        return;
    }
    visited[cur] = true;
    if(prev < cur) edge[prev][cur]--;
    else edge[cur][prev]--;
    
    for(int next : graph[cur]){
        dfs(cur,next);
    }
}

int main(){
    for(int T = 1;; T++){
        int tree = 0; // 트리의 개수
        int N, M; cin >> N >> M; // 정점, 간선 개수
        if(N == 0 && M == 0) break;
        graph.assign(N+1, {});
        edge.assign(N+1, {});
        visited.assign(N+1, false);
        for(int i = 0; i < M; i++){
            int src, dst; cin >> src >> dst;
            graph[src].push_back(dst);
            graph[dst].push_back(src);
            if(src < dst) edge[src][dst]++;
            else edge[dst][src]++;
        }
        for(int i = 1; i <= N; i++){
            if(visited[i]) continue;
            is_graph = false;
            dfs(0, i);
            if(!is_graph) tree++;
        }
        cout <<  "Case " << T << ": ";
        if(tree == 0){
            cout << "No trees.";
        }
        else if(tree == 1){
            cout << "There is one tree.";
        }
        else{
            cout << "A forest of " << tree << " trees.";
        }
        cout << "\n";
    }
    return 0;
}
