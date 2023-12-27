#include <vector>
#include <iostream>
//https://ac.nowcoder.com/acm/contest/72266/B
#include <cmath>
#include <algorithm>
using namespace std;
const int mod = 1e9 + 7;
int main() {
	int n;
	cin >> n;
	vector<int>a(n);
	vector<int>b(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	long long sum1 = 1, sum2 = 1;
	for (int i = 0; i < n; i++) {
		if (a[i] < b[i]) {
			swap(a[i], b[i]);
		}
		sum1 = (sum1 * a[i]) % mod;
		sum2 = (sum2 * b[i]) % mod;
	}

	cout << (sum1 + sum2) % mod << endl;
}