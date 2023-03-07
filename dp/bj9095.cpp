/*------------------------------------------------------------------------
* 문제 번호 | [bj9095] 1, 2, 3 더하기 (실버3)
* 접근 방법 | 점화식
*	1 만들기 = 1개 (1) -> d[1] = 1
*	2 만들기 = 2개 (11, 2) -> d[2] = 2
*	3 만들기 = 4개 (111, 12, 21, 3) -> d[3] = 4
*	4 만들기 = (1111, 112(3), 22, 13(2)) -> d[4] = 7
*	5 만들기 = (11111, 1112(4), 122(3), 23(2), 113(3)) -> d[5] = 13
*	규칙을 찾아보면: d[n] = d[n-3] + d[n-2] + d[n-1]
--------------------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t; // test case
	cin >> t;

	vector<int> d(11);
	int n; // 1 ~ 10
	int i;

	d[1] = 1;
	d[2] = 2;
	d[3] = 4;
	for (int i = 4; i < 11; i++)
		d[i] = d[i - 3] + d[i - 2] + d[i - 1];

	for (i = 0; i < t; i++) {
		cin >> n;
		printf("%d\n", d[n]);
	}
	
	return 0;
}
