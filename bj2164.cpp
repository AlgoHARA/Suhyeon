#include <iostream>
#include <queue>
using namespace std;

/*----------------------------------------
* 문제 번호 | [bj2164] 카드2 (실버4)
* 소요 시간 | 8분
* 체감 난이도 | very easy
------------------------------------------*/

int main() {
	int n; // input
	queue<int> q;
	int i;

	cin >> n;
	for (i = 1; i <= n; i++) {
		q.push(i);
	}

	while (q.size() > 2) {
		q.pop();
		q.push(q.front());
		q.pop();
	}
	
	cout << q.back();

	return 0;
}
