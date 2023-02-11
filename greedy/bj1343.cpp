#include <iostream>
#include <string>
using namespace std;

/*------------------------------------------------------------------
* 문제 번호 | [bj1343] 폴리오미노 (실버5)
* 소요 시간 | 50분
* 체감 난이도 | 쉬울 것 같았으나 쉽지 않았다
* 헤맨 이유 |
*   1. 여전히 문자열 입력을 헤맨다.
*   2. 어느 부분이 반복돼어 어느 만큼을 함수화할지 감을 잡지 못했다.
*   3. check()에서 for문을 언제까지 돌아야 하는지 생각하지 않았다.
-------------------------------------------------------------------*/

string input; // [input]
int num_a = -1;
int num_b = -1;

// input[start]부터 cnt개의 X에 대해 폴리오미노가 존재하는지 확인한다
int check(int cnt, int start) {
	int a, b;
	int temp;
	int max_a = cnt / 4; // A의 개수를 구하기 위해 반복문을 최대 몇 번 돌아야 하는가
	int max_b; // B의 개수를 구하기 위해 반복문을 최대 몇 번 돌아야 하는가

	// cnt개를 만족하는 a, b가 있는지 확인
	for (a = 0; a < max_a + 1; a++) {
		max_b = (cnt - 4 * max_a) / 2;
		for (b = 0; b < max_b + 1; b++) {
			temp = 4 * a + 2 * b;
			if (temp == cnt) {
				num_a = a;
				num_b = b;
			}
		}
	}

	// 폴리오미노가 존재한다
	if (num_a != -1 && num_b != -1) {
		for (a = 0; a < 4 * num_a; a++) {
			input[start + a] = 'A';
		}
		for (b = start + a; b < start + a + 2 * num_b; b++) {
			input[b] = 'B';
		}
		return 0;
	}
	
	// 폴리오미노가 존재하지 않는다
	else {
		return -1;
	}
}

int main() {
	int cnt = 0; // .이 나오기 전까지 연속된 X의 개수
	int i, j;

	cin >> input;
	for (i = 0; i < input.length(); i++) {
		if (input[i] == '.' && cnt > 0) {
			// cnt 개의 X에 대해서 폴리오미노가 존재하는지 확인해야 한다
			if (check(cnt, i - cnt) == -1) {
				cout << -1;
				return 0;
			}

			cnt = 0;
			num_a = -1;
			num_b = -1;
		}

		else if (input[i] == 'X') cnt++;
	}

	// 마지막 cnt개의 X에 대해 처리해줘야 한다
	if (check(cnt, i - cnt) == -1) {
		cout << -1;
		return 0;
	}
	
	cout << input;
	return 0;
}
