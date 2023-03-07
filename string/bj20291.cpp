#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;

int main() {
	string s, ext;
	int n;
	int i, j;
	map<string, int> m;

	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> s;
		for (j = 0; j < s.length(); j++) {
			if (s[j] == '.') break;
		}
		for (++j, ext = ""; j < s.length(); j++) {
			ext += s[j];
		}
		m[ext]++;
	}

	for (auto a : m) {
		cout << a.first << ' ' << a.second << '\n';
	}

	return 0;
}
