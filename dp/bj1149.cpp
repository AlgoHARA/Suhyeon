#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int i, j, tmp;

	int n; // 2 ~ 1,000
	cin >> n;
	vector<vector<int>> cost(n);

	for (i = 0; i < n; i++) {
		for (j = 0; j < 3; j++) { // r g b
			cin >> tmp;
			cost[i].push_back(tmp);
		}
	}

	// 뒤에서부터, 해당 위치에서 r/g/b를 택했을 때 최소 비용
	vector<vector<int>> rgb(n, vector<int>(3));
	rgb[n - 1][0] = cost[n - 1][0]; // r
	rgb[n - 1][1] = cost[n - 1][1]; // g
	rgb[n - 1][2] = cost[n - 1][2]; // b

	for (i = n - 2; i >= 0; i--) {
		// r
		rgb[i][0] = cost[i][0] + min(rgb[i + 1][1], rgb[i + 1][2]);
		// g
		rgb[i][1] = cost[i][1] + min(rgb[i + 1][0], rgb[i + 1][2]);
		// b
		rgb[i][2] = cost[i][2] + min(rgb[i + 1][0], rgb[i + 1][1]);
	}

	printf("%d", min(min(rgb[0][0], rgb[0][1]), rgb[0][2]));

	return 0;
}
