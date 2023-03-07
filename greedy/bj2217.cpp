/*-------------------------------------------------------------
* 문제 번호 | [bj2217] 로프 (실버4)
* 소요 시간 | 15분
* 체감 난이도 | 정렬 아이디어를 생각하지 못했으면 오래 걸렸을 듯..
--------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n; // 1 ~ 100,000
	int i;
	int max = 0;

	cin >> n;
	vector<int> rope(n);
	for (i = 0; i < n; i++) cin >> rope[i];
	sort(rope.begin(), rope.end());

	for (i = 0; i < n; i++) {
		int temp = rope[i] * (n - i);
		if (max < temp) max = temp;
	}

	cout << max;

	return 0;
}
