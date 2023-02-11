#include <iostream>
#include <string>
using namespace std;

/*-----------------------------------------
* 문제 번호 | [bj6603] 로또 (실버2)
* 소요 시간 | GG
* 체감 난이도 | I hate recursion
-------------------------------------------*/

/* 전역 변수 */
int k; // [input] 집합 S에 k개의 숫자가 존재한다
int* num; // [input] numbers 집합
int ans[6]; // [answer] 답으로 출력될 답이 되는 조합
string strAns = ""; // [output]

/* dfs를 이용해 재귀적으로 조합을 탐색한다. */
void dfs(
	int start, // (배열 num에서의 index) 'start부터 마지막 번째 원소 중에 조합을 찾아보겠다' 
	int depth // (dfs의 depth) '배열 ans의 depth번째에, 현재 고려 중인 i번째의 원소를 넣겠다'
) {
	int i;

	// 1. depth가 6에 도달함: 재귀 함수 탈출
	// depth는 0~5까지 있고, 6에 도달하면 재귀 함수를 탈출하게 된다
	if (depth == 6) {
		for (i = 0; i < 5; i++) {
			strAns.append(to_string(ans[i]) + " ");
		}
		strAns.append(to_string(ans[i]) + "\n");
		return;
	}
	// 2. 아직 depth가 6에 도달 안 함: 재귀적으로 함수 실행
	else {
		for (i = start; i < k; i++) {
			ans[depth] = num[i];
			dfs(i + 1, depth + 1); // depth가 6에 도달할 때까지, i 다음 번째의 원소들에 대해 dfs 수행(조합 탐색)
		}
	}
	return;
}

int main() {
	int i;

	while (1) {
		cin >> k;
		if (k == 0) {
			strAns.resize(strAns.length() - 2);
			break;
		}

		num = new int[k];
		for (i = 0; i < k; i++) {
			cin >> num[i];
		}

		// 재귀적으로 dfs 수행
		dfs(0, 0);
		strAns.append("\n");

		delete[] num;
	}

	cout << strAns;
	return 0;
}
