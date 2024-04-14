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

	int n, m, ans = 0;
	cin >> n >> m;

	vector<string> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (s[i][j] == 'A') {
				for (int k = 0; k < j; k++) {
					if (s[i][k] == '*') {
						ans++;
					}
				}
				break;
			} else if (s[i][j] == 'D') {
				for (int k = j + 1; k < m; k++) {
					if (s[i][k] == '*') {
						ans++;
					}
				}
				break;
			}
			else if (s[i][j] == 'W') {
				for (int k = 0; k < i; k++) {
					if (s[k][j] == '*') {
						ans++;
					}
				}
				break;
			}
			else if (s[i][j] == 'S') {
				for (int k = i + 1; k < n; k++) {
					if (s[k][j] == '*') {
						ans++;
					}
				}
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}