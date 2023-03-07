/*------------------------------------------------------------------------
* 문제 번호 | [bj1065] 한수 (실버4)
* 소요 시간 | ..
* 체감 난이도 | 쉬웠는데. 한 자리수씩 구하는 로직 오타 때문에 흙 좀 팠다.
--------------------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int i, tmp, cnt = 0;
	int a, b, c;
	int n; // 1~1000
	cin >> n;

	if (n < 100) {
		cout << n;
		return 0;
	}

	else {
		for (i = 100; i <= n; i++) { // cba
			a = i % 10; // 일의 자리
			tmp = i / 10;
			b = tmp % 10; // 십의 자리
			c = tmp / 10; // 백의 자리

			if (c - b == b - a) cnt++;
		}
	}

	cout << cnt + 99;

	return 0;
}
