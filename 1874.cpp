#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*
 1부터 n까지의 수를 스택에 넣었다가 뽑아 늘어놓음으로써, 하나의 수열을 만들 수 있다.
 이때, 스택에 push하는 순서는 반드시 오름차순을 지키도록 한다고 하자.
 임의의 수열이 주어졌을 때 스택을 이용해 그 수열을 만들 수 있는지 없는지,
 있다면 어떤 순서로 push와 pop 연산을 수행해야 하는지를 알아낼 수 있다.
 이를 계산하는 프로그램을 작성하라.
 */

int main(int argc, const char *argv[]){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    /* stack에 1 넣고 시작 */
    stack<int> nums; nums.push(1);
    int last = 1; // 마지막에 push된 숫자
    string output = "+";
    
    for(int i=0; i < n; i++){
        int num; cin >> num;
        while(last < num){
            nums.push(++last);
            output.append("+");
        }
        if(nums.empty()){
            cout << "NO";
            return 0;
        }
        if(last == num){
            nums.pop();
            output.append("-");
        }
        else{
            if(nums.top()==num){
                nums.pop();
                output.append("-");
            }
            else{
                cout << "NO";
                return 0;
            }
        }
    }
    
    int size = output.size();
    for(int i=0; i<size;i++){
        cout << output[i] << "\n";
    }
    return 0;
}
