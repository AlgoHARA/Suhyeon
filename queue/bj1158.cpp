#include <iostream>
#include <queue>
using namespace std;

/*--------------------------------------------------------------
* 문제 번호		: [bj1158] 요세푸스 문제 (실버4)
* 소요 시간		: 8분
* 체감 난이도	: very easy
---------------------------------------------------------------*/

int main() {
	int n, k; // input
	queue<int> q;
	int i;

	cin >> n;
	cin >> k;

	for (i = 1; i <= n; i++) {
		q.push(i);
	}

	cout << "<";

	while (q.size() > 1) {
		for (i = 0; i < k - 1; i++) {
			q.push(q.front());
			q.pop();
		}
		cout << q.front() << ", ";
		q.pop();
	}

	cout << q.front() << ">" << endl;

	return 0;
}
