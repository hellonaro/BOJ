#include <iostream>
#include <vector>
#include <stack>
#define INF 999999999
using namespace std;

/*
 n(1 ≤ n ≤ 100)개의 도시가 있다.
 그리고 한 도시에서 출발하여 다른 도시에 도착하는 m(1 ≤ m ≤ 100,000)개의 버스가 있다.
 각 버스는 한 번 사용할 때 필요한 비용이 있다.
 모든 도시의 쌍 (A, B)에 대해서 도시 A에서 B로 가는데 필요한 비용의 최솟값과 경로를 구하는 프로그램을 작성하시오.
 */

int main(){
    int n, m; cin >> n >> m;
    int min_cost[101][101];
    vector<int> through[101][101]; // i에서 j로 가기 위해 경유하는 도시
    
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j) min_cost[i][j] = 0;
            else min_cost[i][j] = INF;
        }
    }
    for(int i=0; i<m; i++){
        int a, b, c; cin >> a >> b >> c;
        min_cost[a][b] = min(min_cost[a][b], c);
    }
    
    /* floyd-warshall */
    for(int mid=1; mid<=n; mid++){
        for(int src=1; src<=n; src++){
            for(int dst=1; dst<=n; dst++){
                if(min_cost[src][mid]+min_cost[mid][dst] < min_cost[src][dst]){
                    min_cost[src][dst] = min_cost[src][mid]+min_cost[mid][dst];
                    
                    through[src][dst].clear();
                    for(int city : through[src][mid]){
                        through[src][dst].push_back(city);
                    }
                    through[src][dst].push_back(mid);
                    for(int city : through[mid][dst]){
                        through[src][dst].push_back(city);
                    }
                }
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(min_cost[i][j] == INF) cout << "0 ";
            else cout << min_cost[i][j] << " ";
        }
        cout << endl;
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i == j || min_cost[i][j] == INF){
                cout << "0" << endl;
                continue;
            }
            cout << through[i][j].size()+2 << " ";
            cout << i << " ";
            for(int city : through[i][j]){
                cout << city << " ";
            }
            cout << j;
            cout << endl;
        }
    }
    
    return 0;
}
