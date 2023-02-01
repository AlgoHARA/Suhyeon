#include <stdio.h>
#include <stdlib.h>

// 소요 시간 : 15분

int main() {
	int num[9] = { 0 }; // 0~8의 개수를 저장
	int in, rem;

	scanf("%d", &in);
	while (in != 0) {
		rem = in % 10;
		in = in / 10;
		if (rem == 9) num[6]++;
		else num[rem]++;
	}

	if (num[6] % 2 == 0) num[6] = num[6] / 2; // 짝수 개면
	else num[6] = num[6] / 2 + 1;// 홀수 개면

	// rem : (val) 각 원소 중 최대값
	// in : (index) 을 움직이며 rem과 num[in]을 비교해본다
	for (in = 1, rem = num[0]; in != 9; in++) {
		if (num[in] > rem) rem = num[in];
	}

	printf("%d", rem);
	
	return 0;
}
