#include <iostream>
#include <string>
using namespace std;

/*--------------------------------------------------
* 문제 번호 | [bj2501] 약수 구하기 (브론즈3)
* 소요 시간 | 15분
* 체감 난이도 | tiny bit confusing (for문 반복 횟수)
----------------------------------------------------*/

int main() {
	long n, k; // [input]
	long i;
	long cnt = 0; // n의 약수의 개수

	cin >> n;
	cin >> k;

	for (i = 1; i <= n; i++) {
		if (n % i == 0) { // i는 n의 약수
			cnt++;
			if (cnt == k) break;
		}
	}

	if (cnt < k) cout << 0;
	else cout << i;
	
	return 0;
}
