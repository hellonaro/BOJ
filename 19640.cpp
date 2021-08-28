#include <iostream>
#include <vector>
#define INF 999999999

using namespace std;

/*
 데카는 회사의 화장실을 이용하려고 했다.
 하지만 수도 시설 고장으로 회사 내의 모든 화장실 사용이 금지됐고,
 사원들은 단 하나의 임시 화장실을 이용해야 했다.

 임시 화장실의 앞에 데카를 포함한 N명의 사원이 대기하고 있다.
 데카는 N명의 줄에서 K + 1번째로 줄을 섰다.
 즉, 데카보다 먼저 도착한 사람이 K명이 있다.
 줄이 길어지자 사장은 M개의 줄로 나눠서 대기하라 하였다.

 N명의 사원은 순서대로 M개의 줄로 나눠 섰다.
 기존 줄의 1번째 사원은 1번째 줄에, 2번째 사원은 2번째 줄에, ...
 M번째 사원은 M번째 줄에, 그리고 M + 1번째 사원은 1번째 줄의 뒤에 서는 방식이다.

 M개의 줄로 나눠 선 것을 본 사장은 매우 흡족해하며 자리를 떠났다.

 M개의 줄의 사원들은 암묵적으로 다음의 규칙에 따라 화장실을 이용하기로 하였다.

 선두란, 어떤 줄에서 가장 먼저 와서, 가장 앞에 선 사람을 말한다.
 1. M개의 줄의 선두 중 근무 일수 Di가 가장 높은 선두가 화장실을 이용한다.
 2. M개의 줄의 선두 중 근무 일수 Di가 가장 높은 선두가 둘 이상인 경우,
    해당 선두들 중 화장실이 급한 정도 Hi가 가장 높은 선두가 화장실을 이용한다.
 3. M개의 줄의 선두 중 근무 일수 Di가 가장 높은 선두가 둘 이상이며,
    해당 선두들의 화장실이 급한 정도 Hi도 모두 같다면,
    해당 선두 중 줄의 번호가 가장 낮은 줄에 선 선두가 화장실을 이용한다.
 
 과연 몇 명의 사원이 화장실을 이용하고 나서야 데카의 차례가 올까? 매우 초조해지기 시작한 데카를 대신해 계산해주자.
 */

int main(int argc, const char *argv[]){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N; // 총 직원 수
    int M; cin >> M; // 줄 수
    int K; cin >> K; // 데카 앞 직원 수
    vector<vector<pair<int, int>>> waiting(M+1);
    int deca_d, deca_h;
    pair<int, int> deca_coord; // 데카 좌표
    
    for(int i=1; i<=N; i++){
        int x = i%M;
        int y = i/M;
        if(x==0) {
            x = M;
            y--;
        }
        
        int d; cin >> d;
        int h; cin >> h;
        
        if(i-1 == K){
            deca_d = d;
            deca_h = h;
            deca_coord = make_pair(x, y);
        }
        waiting[x].push_back(make_pair(d,h));
    }
    
    int count = deca_coord.second;
    int min_d = INF, min_h =INF; // 데카네 줄에서 가장 우선 순위 낮은 사람의 d, h
    for(int i=0; i<=deca_coord.second; i++){
        if(min_d > waiting[deca_coord.first][i].first){
            min_d = waiting[deca_coord.first][i].first;
            min_h = waiting[deca_coord.first][i].second;
        }
        if(min_d == waiting[deca_coord.first][i].first){
            if(min_h > waiting[deca_coord.first][i].second){
                min_d = waiting[deca_coord.first][i].first;
                min_h = waiting[deca_coord.first][i].second;
            }
        }
    }
    for(int i=1; i<=M; i++){
        if(i==deca_coord.first) continue;
        int len = waiting[i].size();
        for(int j=0;j<len;j++){
            if(min_d < waiting[i][j].first) {
                count++;
                continue;
            }
            else if(min_d == waiting[i][j].first){
                if(min_h < waiting[i][j].second) {
                    count++;
                    continue;
                }
                else if(min_h == waiting[i][j].second && i<deca_coord.first) {
                    count++;
                    continue;
                }
            }
            break;
        }
    }
        
    cout << count;
    return 0;
}
