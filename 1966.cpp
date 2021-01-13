#include <iostream>
#include <deque>
using namespace std;

/*
일반적인 프린터는 여러분이 인쇄하고자 하는 문서를 인쇄 명령을 받은 ‘순서대로’, 즉 먼저 요청된 것을 먼저 인쇄한다. 
하지만 상근이는 새로운 프린터기 내부 소프트웨어를 개발하였는데, 이 프린터기는 다음과 같은 조건에 따라 인쇄를 하게 된다.
1. 현재 Queue의 가장 앞에 있는 문서의 ‘중요도’를 확인한다.
2. 나머지 문서들 중 현재 문서보다 중요도가 높은 문서가 하나라도 있다면, 이 문서를 인쇄하지 않고 Queue의 가장 뒤에 재배치 한다. 그렇지 않다면 바로 인쇄를 한다.

예를 들어 Queue에 4개의 문서(A B C D)가 있고, 중요도가 2 1 4 3 라면 C를 인쇄하고, 다음으로 D를 인쇄하고 A, B를 인쇄하게 된다.
여러분이 할 일은, 현재 Queue에 있는 문서의 수와 중요도가 주어졌을 때, 어떤 한 문서가 몇 번째로 인쇄되는지 알아내는 것이다.
위의 예에서 C문서는 1번째로, A문서는 3번째로 인쇄된다.
*/

int main() {
    deque<int> printer;
    int N; cin >> N; //테스트 케이스 수
    int M, pos; //문서의 수와 찾으려는 문서의 위치
    int count = 0;  //출력된 문서의 수


    for (int i = 0; i < N; i++) {
        int priority;
        count = 0;
        cin >> M >> pos;
        if (M == 1) {
            cin >> priority;
            cout << "1\n";
            continue;
        }
        for (int j = 0; j < M; j++) {
            cin >> priority;
            printer.push_back(priority);
        }
        for ( ; ; ) {
            bool isBiggest = true;
            for (int j = 1; j < printer.size() && printer.size() > 1 ; j++) {
                if (printer.front() < printer[j]) {
                    isBiggest = false;
                    if (pos == 0) pos = printer.size();
                    printer.push_back(printer.front());
                    printer.pop_front();
                    break;
                }
            }
            if (isBiggest) {
                printer.pop_front();  //문서 출력
                count++;
                if (pos == 0) break;
            }
            pos--;
        }
        cout << count << "\n";
        printer.clear();
    }
}