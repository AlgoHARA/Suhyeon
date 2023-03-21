#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n; // 2~11
int num[100];
int op[4] = { 0 }; // +, -, x, /
long long maxn = -1000000000;
long long minn = 1000000000;

// num[idx]까지 계산해서 result가 나왔다
// 그 result를 num[idx+1]과 어떻게 계산할까?
void dfs(int idx, long long result) {

	if (idx == n - 1) {
		if (maxn < result) maxn = result;
		if (minn > result) minn = result;
		return;
	}

	// +
	if (op[0] > 0) {
		op[0]--;
		dfs(idx + 1, result + num[idx + 1]);
		op[0]++;
	}

	// -
	if (op[1] > 0) {
		op[1]--;
		dfs(idx + 1, result - num[idx + 1]);
		op[1]++;
	}

	// *
	if (op[2] > 0) {
		op[2]--;
		dfs(idx + 1, result * num[idx + 1]);
		op[2]++;
	}

	// /
	if (op[3] > 0) {
		op[3]--;
		if (result >= 0) dfs(idx + 1, result / num[idx + 1]);
		else dfs(idx + 1, (result * -1 / num[idx + 1]) * -1);
		op[3]++;
	}

	return;
}

int main() {
	int i;
	cin >> n;
	for (i = 0; i < n; i++) cin >> num[i];
	for (i = 0; i < 4; i++) cin >> op[i];

	dfs(0, num[0]);

	cout << maxn << '\n' << minn << '\n';

	return 0;
}
