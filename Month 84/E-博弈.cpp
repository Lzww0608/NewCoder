//https://ac.nowcoder.com/acm/contest/72389/E
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>
#include <string>
#include <unordered_map>
using namespace std;
long long a[10000000];
int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		long long sum = 0, zr = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
            zr += (a[i] == 0);
        }
        if (zr * 2 >= n) {
            cout << "Dog" << endl;
            continue;
        }
        if (n == 2) {
            if (abs(a[0] - a[1]) == 1) {
                cout << "Cat" << endl;
            } else {
                cout << "Dog" << endl;
            }
            continue;
        }
        if ((sum - n/2 + 10000000) % 2 == 1) {
            cout << "Dog" << endl;
        } else {
            cout << "Cat" << endl;
        }
	}

	return 0;
}
