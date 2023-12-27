//https://ac.nowcoder.com/acm/contest/72389/A
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>
using namespace std;
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m, X, Y;
		cin >> n >> m >> X >> Y;
		if (X <= Y && n - m >= Y - X) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	return 0;
}
