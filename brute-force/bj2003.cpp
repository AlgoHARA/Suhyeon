#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int n;
	long long m;
	int i, j;
	long long sum;
	int cnt = 0;

	cin >> n >> m;
	vector<int> seq(n);
	for (i = 0; i < n; i++) {
		cin >> seq[i];
	}

	for (i = 0; i < n; i++) {
		sum = seq[i];
		if (sum == m) {
			cnt++;
			continue;
		}
		else if (sum < m) {
			for (j = i + 1; j < n; j++) {
				sum += seq[j];
				if (sum < m) continue;
				else if (sum == m) {
					cnt++;
					break;
				}
				else break;
			}
		}
		else continue;
	}
	
	cout << cnt << '\n';

	return 0;
}
