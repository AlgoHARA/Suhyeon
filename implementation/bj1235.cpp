#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, i, j, len;
	cin >> n;
	vector<string> v(n);
	vector<int> cut(n);
	vector<int> tmp(n);

	for (i = 0; i < n; i++) {
		cin >> v[i];
	}

	// 뒤에서 i까지만 했을 때 어때!
	len = v[0].length();
	for (i = 0; i < len; i++) {
		cut.clear();
		tmp.clear();

		for (j = 0; j < n; j++) {
			cut.push_back(stoi(v[j].substr(len - i - 1, i + 1)));
			tmp.push_back(stoi(v[j].substr(len - i - 1, i + 1)));
		}
		sort(tmp.begin(), tmp.end());
		tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());

		if (tmp.size() == cut.size()) {
			printf("%d\n", i + 1);
			break;
		}
	}

	return 0;
}
