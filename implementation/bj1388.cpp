#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/*------------------------------------------
* 문제 번호 | [bj1388] 바닥 장식 (실버4)
* 소요 시간 | 30분
* 체감 난이도 | SO SO
-------------------------------------------*/

int main() {
	int n, m; // [input]
	int i, j;
	char temp;

	int hcnt; // 현재 가로 타일의 개수
	int vcnt; // 현재 세로 타일의 개수
	int t_hcnt = 0; // 총 필요한 가로 타일의 개수
	int t_vcnt = 0; // 총 필요한 세로 타일의 개수

	cin >> n;
	cin >> m;
	vector<vector<pair<char, bool>>> input(n, vector<pair<char, bool>>(m, make_pair('.', false)));
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> temp;
			input[i][j].first = temp;
		}
	}

	for (i = 0; i < n; i++) {
		hcnt = 0;
		for (j = 0; j < m; j++) {
			if (input[i][j].first == '-') {
				if (hcnt == 0) {
					hcnt++;
					continue;
				}
				if (input[i][j - 1].first == '-') {
					hcnt++;
					continue;
				}
			}
			else { // '|' : 
				if (hcnt > 0) { // 가로가 나오다가 끊겼으니 거기까지가 가로 타일
					t_hcnt++;
					hcnt = 0;
				}

				// 첫번째 줄에선: '|'가 있으면 무조건 ++
				if (i == 0) {
					t_vcnt++;
				}
				// 나머지 줄에선: 항상 한 층 위에 껄 확인 하자
				else {
					// 윗층도 '|'면: 이미 고려됐으니 t_vcnt 안 추가해도 돼
					if (input[i - 1][j].first == '|') continue;
					// 윗층은 '|' 아니면: t_vcnt 추가해야 돼
					else t_vcnt++;
				}

				input[i][j].second = true; // 이 타일은 고려됐다는 뜻
			}
		}
		if (hcnt > 0) t_hcnt++;
	}

	printf("%d\n", t_hcnt + t_vcnt);

	return 0;
}
