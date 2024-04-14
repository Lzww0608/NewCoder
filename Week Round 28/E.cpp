#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll mod = 1e9 + 7;

ll quickPower(ll b, ll v) {
    ll res = 1LL;
    while (v > 0) {
        if (v % 2 == 1) {
            res = res * b % mod;
        }
        v /= 2;
        b = b * b % mod;
    }
    return res;
}

int main() {
    
    int n, k;
    cin >> n >> k;
    
    int even = k / 2, odd = k - even;
    //even even even ...
    ll r1 = quickPower(even, n); 
    //odd odd even odd odd even ...
    ll r2 = quickPower(even, n/3) * quickPower(odd, n - n/3) % mod;
    //odd even odd odd even odd ...
    ll r3 = quickPower(even, (n+1)/3) * quickPower(odd, n-(n+1)/3) % mod;
    //even odd odd even odd odd ...
    ll r4 = quickPower(even, (n+2)/3) * quickPower(odd, n-(n+2)/3) % mod;
    
    ll res = (r1 + r2 + r3 + r4) % mod;
    cout << res << endl;
    
    return 0;
}