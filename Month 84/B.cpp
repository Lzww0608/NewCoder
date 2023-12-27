//https://ac.nowcoder.com/acm/contest/72389/B
#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        int g, l;
        cin >> g >> l; 
        
        if (l % g != 0) {
            cout << "-1" << endl;
            continue;
        }

        int a = g, b = g;

        for (; a <= l * g / a; a += g) {
            b = l * g / a;
            if (a * b == g * l) {
                cout << a << " " << b << endl;
                break;
            }
        }
        if (a > b) {
            cout << "-1" << endl;
        }
    }
   
    return 0;
}

