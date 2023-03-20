#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main() {
	string s;
	int l, r;

	cin >> s;
	int len = s.length();
	int mid = s.length() / 2;

	// 그 자체로 팰린드롬인가?
	l = mid - 1; r = mid;
	if (len % 2 == 1) r++;
	while (l != -1) {
		if (s[l] == s[r]) {
			l--; r++;
		}
		else break;
	}

	if (l == -1) { // 팰린드롬이 맞다
		cout << len << '\n';
		return 0;
	}
	
	// 팰린드롬을 만들 때까지 검사해본다
	if (len % 2 != 0) mid++; // mid 초기화

	// mid를 기준으로 양쪽을 검사할 것이다
	while (mid != len) {
		// 1. mid가 홀수 개에서 가운데 라면?
		l = mid - 1; r = mid + 1;
		while (r != len) {
			if (s[l] == s[r]) {
				l--; r++;
			}
			else break;
		}
		if (r == len) { // 팰린드롬이다
			cout << mid * 2 + 1;
			return 0;
		}

		// 2. mid가 짝수 개에서 가운데(왼쪽) 이라면?
		l = mid; r = mid + 1;
		while (r != len) {
			if (s[l] == s[r]) {
				l--; r++;
			}
			else break;
		}
		if (r == len) { // 팰린드롬이다
			cout << (mid + 1) * 2;
			return 0;
		}

		// 팰린드롬이 안 나왔다
		mid++;
	}

	if (len % 2 == 0) cout << len * 2 - 1;
	else cout << len * 2;
	return 0;
}
