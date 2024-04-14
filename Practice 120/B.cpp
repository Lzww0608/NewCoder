#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    int a, b, c, m;
    cin >> T;
    auto gcd = [](int a, int b) -> int {
        while (b) {
            int t = b;
            b = a % b;
            a = t;
        }  
        return a;
    };
    while(T--) {
        cin >> a >> b >> c >> m;
        int g = gcd(gcd(a, b), c);
        if (m % g == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}