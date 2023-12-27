//https://ac.nowcoder.com/acm/contest/72266/A
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>a(n);
	vector<char>b(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		if (b[i] == 'T') {
			ans += a[i];
		}
		else {
			ans += max(5, a[i] / 100);
		}
	}
	cout << ans << endl;
}