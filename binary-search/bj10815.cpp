#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/*-----------------------------------------------------------------------------------
* 문제 번호 | [bj10815] 숫자 카드 (실버5)
* 소요 시간 | 23분
* 체감 난이도 | SO SO
*
* 유의할 점 |
*	  - 입출력 빠르게 하려면 버퍼간 tie 끊기
*	  - 배열 넘길 땐 &(참조자)로 넘기기
*           그렇지 않으면 함수가 호출될 때마다 매번 벡터의 모든 내용이 깊은 복사 돼서(호출만 O(n))
*           이분 탐색인 O(log(n))보다 시간 복잡도가 나쁘다.
------------------------------------------------------------------------------------*/

int search(int target, vector<int> &input) {
	int low, mid, high;

	low = 0;
	high = input.size() - 1;

	while (low <= high) {
		mid = (low + high) / 2;

		if (input[mid] == target) return 0; // target 발견

		if (input[mid] < target) low = mid + 1;
		else high = mid - 1;
	}

	return 1; // target 못 발견
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n, m; // input
	int i;
	int tmp;

	cin >> n; // 1 ~ 500,000
	vector<int> input(n, 0);
	for (i = 0; i < n; i++) {
		cin >> tmp; // 각자 -10,000,000 ~ 10,000,000
		input[i] = tmp;
	}

	sort(input.begin(), input.end()); // 이진 탐색 전 오름차순 정렬

	cin >> m; // 1 ~ 500,000
	for (i = 0; i < m; i++) {
		cin >> tmp; // tmp가 input 내에 존재하는지 찾아야 한다

		if (search(tmp, input) == 0) cout << "1 ";
		else cout << "0 ";
	}

	return 0;
}
