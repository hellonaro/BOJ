#include <iostream>
#include <string>
#include <stack>
using namespace std;

/*
 상근이는 문자열에 폭발 문자열을 심어 놓았다. 폭발 문자열이 폭발하면 그 문자는 문자열에서 사라지며, 남은 문자열은 합쳐지게 된다.
 폭발은 다음과 같은 과정으로 진행된다.
 1. 문자열이 폭발 문자열을 포함하고 있는 경우에, 모든 폭발 문자열이 폭발하게 된다. 남은 문자열을 순서대로 이어 붙여 새로운 문자열을 만든다.
 2. 새로 생긴 문자열에 폭발 문자열이 포함되어 있을 수도 있다.
 3. 폭발은 폭발 문자열이 문자열에 없을 때까지 계속된다.
 상근이는 모든 폭발이 끝난 후에 어떤 문자열이 남는지 구해보려고 한다. 남아있는 문자가 없는 경우가 있다. 이때는 "FRULA"를 출력한다.
 폭발 문자열은 같은 문자를 두 개 이상 포함하지 않는다.
 */

int main(int argc, const char *argv[]){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string input; cin >> input;
    string bomb; cin >> bomb;
    string output;
    int len_input = input.length();
    int len_bomb = bomb.length();
    
    for(int i=0; i < len_bomb-1; i++){
        output.push_back(input[i]);
    }
    
    for(int i=len_bomb-1; i < len_input; i++){
        stack<char> tmp;
        output.push_back(input[i]);
        for(int j=0; bomb[len_bomb-1-j]==output.back() && j<len_bomb; j++){
            char last = output.back();
            tmp.push(last);
            output.pop_back();
        }
        if(tmp.size() != len_bomb){
            for(;!tmp.empty();){
                output.push_back(tmp.top());
                tmp.pop();
            }
        }
    }
    
    if(output.size()!=0){
        cout << output;
    }
    else{
        cout << "FRULA";
    }
    return 0;
}
