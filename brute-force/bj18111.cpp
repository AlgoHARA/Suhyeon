#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, invt;
vector<int> ground;

int main() {
	int i, j, h;
	int min_t = 0x7f7f7f7f, max_h = 0;

	cin >> n >> m >> invt;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> h;
			ground.push_back(h);
		}
	}

	sort(ground.begin(), ground.end());

	// 땅의 높이가 0~256까지 가능
	// 기준이 될 땅의 높이를 h라고 하고, h에 맞춰 블록을 빼거나 추가하겠다
	for (h = 0; h <= 256; h++) {
		int build = 0; // 추가할 블록 개수
		int remove = 0; // 인벤토리로 뺄 블록 개수
		
		// h로 맞추려면 몇 개의 블록을 추가/제거해야 하는지 계산
		for (i = 0; i < ground.size(); i++) {
			int dif = ground[i] - h;
			if (dif > 0) remove += dif;
			else if (dif < 0) build -= dif;
		}

		// h가 현실적으로 가능한지 본다 (invt에 있는 블록이 build개보다 충분한가?)
		if (remove + invt >= build) { // 그렇담 h는 가능하다
			int t = remove * 2 + build;
			if (t <= min_t) {
				min_t = t;
				max_h = h;
			}
		}
	}

	cout << min_t << ' ' << max_h << '\n';

	return 0;
}
