#include <stdio.h>
#include <stdlib.h>

/*---------------------------------------------
* 문제 번호 | [bj1051] 숫자 정사각형 (실버4)
* 소요 시간 | 1시간
* 체감 난이도 | not easy but I could made it
----------------------------------------------*/

int main() {
	int row; // input 정사각형의 행의 수
	int col; // input 정사각형의 열의 수
	char str[51]; // input 한 줄
	int** input; // input 정사각형

	int a, b;
	int cur = 1; // 현재 확인중인 정사각형의 한 변의 길이
	int max = 1; // 확인을 시작해야 하는 최대 정사각형 한 변의 길이
	// 답은 max^2가 돼야 함

	scanf("%d %d", &row, &col);

	input = (int**)malloc(sizeof(int*) * row);
	for (a = 0; a < row; a++)
		input[a] = (int*)malloc(sizeof(int) * col);

	for (a = 0; a < row; a++) {
		scanf("%s", str);
		for (b = 0; b < col; b++)
			input[a][b] = str[b] - 48;
	}

	// cur은 계속 바뀔거야
	for (a = 0; a + max < row; a++) {
		for (b = 0; b + max < col; b++) {
			// input[a][b]에 대해서 확인해본다
			cur = max;
			while (a + cur < row && b + cur < col) {
				if ((input[a][b] != input[a][b + cur]) || // 꼭짓점2
					(input[a][b] != input[a + cur][b]) || // 꼭짓점3
					(input[a][b] != input[a + cur][b + cur])) // 꼭짓점4
				{
					cur++;
					continue; // 다른 크기의 정사각형 확인해보자
				}

				// 모든 꼭짓점이 같음을 확인했다
				max = ++cur;
			}
		}
	}

	printf("%d\n", max * max);

	for (a = 0; a < row; a++)
		free(input[a]);
	free(input);

	return 0;
}
