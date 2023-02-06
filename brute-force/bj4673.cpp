#include <iostream>
#include <string>
using namespace std;

/*----------------------------------------------------------
* 문제 번호 | [bj4673] 셀프 넘버 (실버5)
* 소요 시간 | 25분
* 체감 난이도 | 유효한 배열 index인지 체크를 안 해서 큰일날 뻔
------------------------------------------------------------*/

bool num[10001] = { false };
int com[4]; // combination of 4 numbers

void dfs(
	int start,
	int depth
) {
	int i;

	if (depth == 4) {
		i = 1001 * com[0] + 101 * com[1] + 11 * com[2] + 2 * com[3];
		if (i < 10000) num[i] = true;
		return;
	}

	for (i = 0; i < 10; i++) {
		com[depth] = i;
		dfs(i + 1, depth + 1);
	}
}

int main() {
	int i;

	dfs(0, 0);

	for (i = 1; i < 10000; i++) {
		if (num[i] == false)
			cout << i << endl;
	}

	return 0;
}
