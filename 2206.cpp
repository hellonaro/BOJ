#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

/*
 N×M의 행렬로 표현되는 맵이 있다.
 맵에서 0은 이동할 수 있는 곳을 나타내고, 1은 이동할 수 없는 벽이 있는 곳을 나타낸다.
 당신은 (1, 1)에서 (N, M)의 위치까지 이동하려 하는데, 이때 최단 경로로 이동하려 한다.
 최단경로는 맵에서 가장 적은 개수의 칸을 지나는 경로를 말하는데,
 이때 시작하는 칸과 끝나는 칸도 포함해서 센다.

 만약에 이동하는 도중에 한 개의 벽을 부수고 이동하는 것이 좀 더 경로가 짧아진다면,
 벽을 한 개 까지 부수고 이동하여도 된다.
 한 칸에서 이동할 수 있는 칸은 상하좌우로 인접한 칸이다.

 맵이 주어졌을 때, 최단 경로를 구해 내는 프로그램을 작성하시오.
 */

int N, M; // 행렬 크기
vector<vector<char>> graph;
vector<vector<int>> dist[2];
vector<vector<bool>> visited[2];
queue<tuple<int, int, int>> q; // 부신 벽의 유무, x좌표, y좌표

bool isInRange(int x, int y){
    if(x<0 || x>=N) return false;
    if(y<0 || y>=M) return false;
    return true;
}

int main(){
    int ans = -1;
    cin >> N >> M;
    graph.assign(N, vector<char>(M));
    dist[0].assign(N, vector<int>(M));
    dist[1].assign(N, vector<int>(M));
    visited[0].assign(N, vector<bool>(M));  // 벽 안 부신 상태에서 방문
    visited[1].assign(N, vector<bool>(M));  // 벽 부신 상태에서 방문
    
    for(int x=0; x<N; x++){
        for(int y=0; y<M; y++){
            cin >> graph[x][y];
        }
    }
    
    dist[0][0][0] = 1;
    q.push(make_tuple(0,0,0));
    visited[0][0][0] = true;
    
    int beside[4][2] ={{0, -1},{0, 1},{-1, 0},{1, 0}};
    while(!q.empty()){
        int broken = get<0>(q.front()); // 부셨다면 1 아니라면 0
        int x = get<1>(q.front());
        int y = get<2>(q.front());
        int cur_dist = dist[broken][x][y];
        q.pop();
        
        for(int i=0; i<4; i++){
            int new_broken = broken;
            int new_x = x+beside[i][0];
            int new_y = y+beside[i][1];
                
            if(isInRange(new_x, new_y)){
                if(graph[new_x][new_y] == '1'){
                    if(broken == 1) continue;
                    else new_broken = 1;
                }
                if(visited[new_broken][new_x][new_y]) continue;
                dist[new_broken][new_x][new_y] = cur_dist + 1;
                q.push(make_tuple(new_broken,new_x,new_y));
                visited[new_broken][new_x][new_y] = true;
            }
        }
    }
    
    if(visited[0][N-1][M-1] || visited[1][N-1][M-1]){
        if(!visited[1][N-1][M-1]) ans = dist[0][N-1][M-1];
        else if(!visited[0][N-1][M-1]) ans = dist[1][N-1][M-1];
        else ans = min(dist[0][N-1][M-1], dist[1][N-1][M-1]);
    }
    
    cout << ans;
    return 0;
}
