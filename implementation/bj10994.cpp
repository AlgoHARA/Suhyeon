/*---------------------------------------------
* 문제 번호 | [bj10994] 별 찍기 - 19 (실버4)
* 소요 시간 | 20분
* 체감 난이도 | I CAN DO IT
---------------------------------------------**/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	int i, j;

	if (n == 1) {
		printf("*");
		return 0;
	}

	for (i = 0; i < 4 * n - 3; i++) printf("*");
	printf("\n");

	for (i = 1; i <= 2 * n - 2; i++) {
		if (i % 2 == 1) { // 홀수 행
			for (j = 0; j <= i / 2; j++) printf("* ");
			for (j = 0; j < 4 * n - 3 - (i+1) * 2; j++) printf(" ");
			for (j = 0; j <= i / 2; j++) printf(" *");
			printf("\n");
		}
		else { // 짝수 행
			for (j = 0; j < i / 2; j++) printf("* ");
			for (j = 0; j < 4 * n - 3 - i * 2; j++) printf("*");
			for (j = 0; j < i / 2; j++) printf(" *");
			printf("\n");
		}
	}

	for (i = 2 * n - 3; i >= 1; i--) {
		if (i % 2 == 1) { // 홀수 행
			for (j = 0; j <= i / 2; j++) printf("* ");
			for (j = 0; j < 4 * n - 3 - (i + 1) * 2; j++) printf(" ");
			for (j = 0; j <= i / 2; j++) printf(" *");
			printf("\n");
		}
		else { // 짝수 행
			for (j = 0; j < i / 2; j++) printf("* ");
			for (j = 0; j < 4 * n - 3 - i * 2; j++) printf("*");
			for (j = 0; j < i / 2; j++) printf(" *");
			printf("\n");
		}
	}

	for (i = 0; i < 4 * n - 3; i++) printf("*");
	printf("\n");

	return 0;
}
