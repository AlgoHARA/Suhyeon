#include <stdio.h>
#include <stdlib.h>

int main() {
	int ppl[9] = { 0 };
	char str[3];
	int i, j, cur;
	int sum;

	// 9명의 키를 입력받아 int형 배열에 저장
	for (i = 0; i != 9; i++) {
		scanf("%s", str);
		ppl[i] = atoi(str);
	}

	// i, j-th를 제외하고 나머지 원소들(cur-th)의 합을 구해본다
	for (i = 0, j = 1; i != 7; ) {
		// 초기화
		cur = 0; sum = 0;
		// cur-th 원소들의 합을 구해본다
		while (cur != 9) {
			if (cur == i || cur == j) {
				cur++;
				continue;
			}
			sum += ppl[cur++];
		}

		// 7개 원소들의 합이 100이면: 반복문 종료
		if (sum == 100) break;
		// 아니라면: i, j값 변경
		else {
			if (j == 8) {
				i++; j = i + 1;
			}
			else j++;
		}
	}

	// 제외되는 두 원소와 0, 1-th 원소를 swap
	ppl[i] = ppl[0]; ppl[j] = ppl[1];

	// 배열의 2~8-th를 오름차순 정렬
	// i : 몇 번째 index부터 최소값을 찾으면 되는지 알려준다
	// j : 움직이며 ppl[cur]보다 최소값이 있는지 확인한다
	// cur : 최소값이 위치한 곳의 index
	i = 2;
	while (i != 8) {
		for (cur = i, j = i + 1; j != 9; j++) {
			if (ppl[cur] > ppl[j]) cur = j;
		}
		// cur-th가 최소값임을 확인했다
		printf("%d\n", ppl[cur]);
		if (i != cur) ppl[cur] = ppl[i];
		i++;
	}
	printf("%d\n", ppl[i]);
	
	return 0;
}
