#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

int n; // 3~8
int input[8];
vector<int> result;
bool visited[8];
int maxi = -1;

void dfs_permu(int cnt) {
	int i, diff, sum = 0;

	if (cnt == n) { // result 완성됨
		for (i = 0; i < n - 1; i++) {
			diff = result[i] - result[i + 1];
			if (diff < 0) diff *= -1;
			sum += diff;
		}
		if (sum > maxi) maxi = sum;
		return;
	}

	for (i = 0; i < n; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		result.push_back(input[i]);
		dfs_permu(cnt + 1);
		result.pop_back();
		visited[i] = false;
	}

}

int main() {
	int i;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> input[i];
	}
	
	dfs_permu(0);

	cout << maxi << '\n';
	return 0;
}
