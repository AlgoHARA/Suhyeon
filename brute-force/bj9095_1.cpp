/*------------------------------------------------------------------------
* 문제 번호 | [bj9095] 1, 2, 3 더하기 (실버3)
* 소요 시간 | 40분
* 체감 난이도 | NOT BAD BUT... DP로 어떻게 풀지
--------------------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t; // test case
	int n; // 1 ~ 10
	int i, j;
	int a, b, c;
	
	cin >> t;
	vector<int> input(t);
	for (i = 0; i < t; i++) cin >> input[i];

	for (i = 0; i < t; i++) {
		n = input[i];

		int cnt = 0;

		// n = 1 * a + 2 * b + 3 * c (a, b, c는 0~?개)
		for (a = 0; a <= n; a++) {

			for (b = 0; b <= n / 2; b++) {

				if (a + b * 2 > n) break;

				for (c = 0; c <= n / 3; c++) {

					if (a + b * 2 + c * 3 > n) break;

					if (a + b * 2 + c * 3 == n) {
						int sum = a + b + c;
						int temp = 1;
						for (j = 2; j <= sum; j++) temp *= j;
						if (a >= 2) for (j = 2; j <= a; j++) temp /= j;
						if (b >= 2) for (j = 2; j <= b; j++) temp /= j;
						if (c >= 2) for (j = 2; j <= c; j++) temp /= j;
						cnt += temp;
					}
				}
			}
		}

		printf("%d\n", cnt);
	}

	return 0;
}
