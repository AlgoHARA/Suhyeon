#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

int n; // 재료의 개수, 1~10
vector<pair<long long, long long>> v; // <s 신맛, b 쓴맛>
bool visited[11] = { false };
long long mini = 1000000000;

void print_combi() {
	long long s_mul = 1;
	long long b_sum = 0;
	long long diff = 0;

	for (int i = 0; i < n; i++) {
		if (visited[i]) {
			//cout << v[i].first << ' ' << v[i].second << '\n';
			s_mul *= v[i].first;
			b_sum += v[i].second;
		}
	}

	diff = s_mul - b_sum;
	if (diff < 0) diff = diff * -1;
	if (diff < mini) mini = diff;

	return;
}

void dfs_combi(int start) {
	for (int i = start; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			print_combi();
			dfs_combi(i);
			visited[i] = false;
		}
	}

	return;
}

int main() {
	int i;
	long long s, b;
	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> s >> b;
		v.push_back(make_pair(s, b));
	}

	if (n == 1) {
		if (s > b) cout << s - b << '\n';
		else cout << b - s << '\n';
	}

	else {
		dfs_combi(0);
		cout << mini << '\n';
	}

	return 0;
}
