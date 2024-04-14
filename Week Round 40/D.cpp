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

	ll n, x;
	cin >> n >> x;
	ll a, b, c, d, e;
	vector<ll> f(x + 1), g(x + 1);
	while (n--) {
		g = f;
        cin >> a >> b >> c >> d >> e;
		for (ll i = 0; i <= min(e, x); i++) {
			ll cost = b + i * c;
			for (ll j = cost; j <= x; j++) {
				g[j] = max(g[j], f[j - cost] + a + i * d);
			}
		}
		f = g;
	}
	cout << *max_element(f.begin(), f.end()) << endl;

	return 0;
}