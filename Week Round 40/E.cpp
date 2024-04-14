 #include <bits/stdc++.h>
using namespace std;


int main() {
    long long n, x, y;
    cin >> n >> x >> y;
    
    cout << max({n * n / 3 * x, n * n / 4 *y, n * n / 3 * x - x + y}) << endl;
}