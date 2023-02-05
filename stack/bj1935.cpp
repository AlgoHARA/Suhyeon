#include <iostream>
#include <stack>
using namespace std;

/*---------------------------------------------------------------------
* 문제 번호 | [bj1935] 후위 표기식2 (실버3)
* 소요 시간 | 2시간 50분
* 체감 난이도 | I'm so mad
* 헤맨 이유 |
*	1) '후!위 표기식'이니, 인자들을 뒤에서부터 연산했다.
*	2) 연산자 +, -가 나오면, *, /가 나올 때까지 기다려야 한다고 생각했다.
*		괄호로 묶여 있는 경우 그럴 수 있겠지만 이 문제는 괄호가 없다.
----------------------------------------------------------------------*/

int main() {
	int n; // [input] 피연산자의 개수
	string str; // [input] 후위 표기식
	double* num; // [input] 0th에 A값, 1th에 B값, ... 저장
	int i;
	double n1, n2;

	stack<char> op; // 연산자 저장
	stack<double> param; // 숫자 저장

	cin >> n;
	num = new double[n];
	cin >> str;

	for (i = 0; i < n; i++) {
		cin >> num[i];
	}

	// 문자열의 뒤에서부터 접근
	for (i = 0; i <= str.length() - 1; i++) {
		// 1. 알파벳이 나왔다
		if (65 <= int(str[i]) && int(str[i]) <= 90) {
			param.push(num[str[i] - 65]);
		}

		// 2. 연산자가 나왔다
		else { 
			n1 = param.top();
			param.pop();
			n2 = param.top();
			param.pop();
			switch (str[i]) {
				case '*':
					param.push(n1 * n2);
					break;
				case '/':
					param.push(n2 / n1);
					break;
				case '+':
					param.push(n1 + n2);
					break;
				case '-':
					param.push(n2 - n1);
			}
		}
	}

  // 소수점 둘째 자리까지만 출력
	cout << fixed;
	cout.precision(2);
	cout << param.top() << endl;

	delete[] num;

	return 0;
}
