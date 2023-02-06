#include <iostream>
#include <string>
using namespace std;

/*-------------------------------------------
* 문제 번호 | [bj17478] 재귀함수가 뭔가요? (실버5)
* 소요 시간 | 25분
* 체감 난이도 | 재귀는 아직까지 익숙지 않다..
--------------------------------------------*/

int n;
string str[7];

void recursion(int depth) {
	int i, j;

	if (depth == n) {
		for (j = 0; j < depth * 4; j++) cout << "_";
		cout << str[1];
		for (j = 0; j < depth * 4; j++) cout << "_";
		cout << str[6];
		for (j = 0; j < depth * 4; j++) cout << "_";
		cout << str[5];
		return;
	}

	for (i = 1; i < 5; i++) {
		for (j = 0; j < depth * 4; j++) {
			cout << "_";
		}
		cout << str[i];
	}
	recursion(depth + 1);

	for (j = 0; j < depth * 4; j++) {
		cout << "_";
	}
	cout << str[i];
}

int main() {
	int i, j;

	cin >> n;

	str[0] = "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
	str[1] = "\"재귀함수가 뭔가요?\"\n";
	str[2] = "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
	str[3] = "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
	str[4] = "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
	str[5] = "라고 답변하였지.\n";
	str[6] = "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
	
	for (i = 0; i < 5; i++) cout << str[i];
	
	recursion(1);

	cout << str[5];
	return 0;
}
