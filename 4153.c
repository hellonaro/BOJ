#include <stdio.h>

/*
과거 이집트인들은 각 변들의 길이가 3, 4, 5인 삼각형이 직각 삼각형인것을 알아냈다. 
주어진 세변의 길이로 삼각형이 직각인지 아닌지 구분하시오.
*/

int main() {
	int temp;
	int arr[3];
	while (1) {
		scanf("%d", &arr[0]);
		scanf("%d", &arr[1]);
		if (arr[0] > arr[1]) {
			temp = arr[0];
			arr[0] = arr[1];
			arr[1] = temp;
		}
		scanf("%d", &arr[2]);
		if (arr[1] > arr[2]) {
			temp = arr[1];
			arr[1] = arr[2];
			arr[2] = temp;
		}
		if (arr[0] + arr[1] + arr[2] == 0) break;
		if (arr[2] * arr[2] == arr[0] * arr[0] + arr[1] * arr[1]) 
			printf("right\n");
		else printf("wrong\n");
	}
}