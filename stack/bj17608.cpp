#include <iostream>
#include <stack>
using namespace std;

/*-----------------------------------------------
* 문제 번호 | [bj17608] 막대기 (브론즈2)
* 소요 시간 | 14분
* 체감 난이도 | easy
------------------------------------------------*/

int main() {
	int n; // [input] 막대기의 개수
	int cur; // [input] 각 막대의 높이; 현재 스택의 가장 위에 있는 것
	int i;
	int num = 0; // [output]
	int max = 0;
	stack<int> stack;

	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> cur;
		stack.push(cur);
	}

	while (!stack.empty()) {
		cur = stack.top();
		stack.pop();
		if (cur > max) {
			max = cur;
			num++;
		}
	}

	cout << num;

	return 0;
}
