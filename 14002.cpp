#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
 수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.
 예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에
 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.
 */

int main(){
    int a; cin >> a;
    vector<pair<int, int>> numbers(a);
    vector<int> dist(a, 1);
    
    int ans = 1;
    int ans_idx = 0;
    for(int i=0; i<a; i++){
        int num; cin >> num;
        numbers[i].first = num;
        numbers[i].second = -1;
    }
    
    for(int i=0; i<a; i++){
        for(int j=i+1; j<a; j++){
            if(numbers[i].first < numbers[j].first){
                if(dist[i]+1 > dist[j]){
                    dist[j] = dist[i]+1;
                    numbers[j].second = i;
                    if(dist[j] > ans){
                        ans = dist[j];
                        ans_idx = j;
                    }
                }
            }
        }
    }
    
    stack<pair<int, int>> s;
    s.push(numbers[ans_idx]);
    while(s.top().second >= 0){
        int before_idx = s.top().second;
        s.push(numbers[before_idx]);
    }
    
    cout << ans << endl;
    while(!s.empty()){
        cout << s.top().first << " ";
        s.pop();
    }

    return 0;
}
