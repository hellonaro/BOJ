#include <iostream>
#include <deque>
using namespace std;

/*
어떤 나라에 N개의 도시가 있다. 이 도시들은 일직선 도로 위에 있다. 편의상 일직선을 수평 방향으로 두자. 
제일 왼쪽의 도시에서 제일 오른쪽의 도시로 자동차를 이용하여 이동하려고 한다. 
인접한 두 도시 사이의 도로들은 서로 길이가 다를 수 있다. 도로 길이의 단위는 km를 사용한다.
처음 출발할 때 자동차에는 기름이 없어서 주유소에서 기름을 넣고 출발하여야 한다. 
기름통의 크기는 무제한이어서 얼마든지 많은 기름을 넣을 수 있다. 도로를 이용하여 이동할 때 1km마다 1리터의 기름을 사용한다. 
각 도시에는 단 하나의 주유소가 있으며, 도시 마다 주유소의 리터당 가격은 다를 수 있다. 가격의 단위는 원을 사용한다.
각 도시에 있는 주유소의 기름 가격과, 각 도시를 연결하는 도로의 길이를 입력으로 받아 제일 왼쪽 도시에서 제일 오른쪽 도시로 이동하는 최소의 비용을 계산하는 프로그램을 작성하시오.
*/

int main() {
	int N; cin >> N;
	deque<int> distance;
	deque<int> price;
	long long total = 0;

	for (int i = 0; i < N - 1; i++) {
		int tmp; cin >> tmp;
		distance.push_back(tmp);
	}
	for (int i = 0; i < N; i++) {
		int tmp; cin >> tmp;
		price.push_back(tmp);
	}
	for (int i = 0; i < N-1; i++) {
		if (price[i] < price[i+1]) price[i+1] = price[i];
		total += (long long)price[i] * distance[i];
	}
	cout << total;
}