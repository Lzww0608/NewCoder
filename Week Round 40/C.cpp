#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;


int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	unordered_map<int, int> cnt;
	vector<int> p(n), q(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		cnt[a[i]]++;
		if (cnt[a[i]] > 2) {
			cout << -1 << endl;
			return 0;
		}
	}

	vector<int> vis(n + 1, 0);
	vector<int> t(n + 1, 0);
	for (int i = 0; i < n; ++i) {
		int x = a[i];
		if (vis[x] == 0) {
			vis[x] = 1;
			p[i] = x;
		}
		else {
			q[i] = x;
			t[x] = 1;
		}
	}

	int i = 0, j = 1;
	while (i < n) {
		while (i < n && p[i] != 0) {
			i++;
		}
		while (j <= n && vis[j] != 0) {
			j++;
		}
		if (i < n && j <= n) {
			p[i] = j;
			i++; j++;
		}
	}

	i = 0; j = 1;
	while (i < n) {
		while (i < n && q[i] != 0) {
			i++;
		}
		while (j <= n && t[j] != 0) {
			j++;
		}
		if (i < n && j <= n) {
			q[i] = j;
			i++; j++;
		}
	}

	for (int x : p) {
		cout << x << " ";
	}
	cout << endl;
	for (int x : q) {
		cout << x << " ";
	}
	cout << endl;


	return 0;
}