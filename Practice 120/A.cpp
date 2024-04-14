#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(0);
    int T, n, a;
    cin >> T;
    while (T--) {
        cin >> n;
        int b = 0, cnt = 0;
        for (int i = 0; i < n - 1; i++) {
            cin >> a;
            if (b < a) {
                b = a;
                cnt = 1;
            } else if (b == a) {
                cnt++;
            }
        }
        if (cnt == n - 1) {
            cout << "1" << endl;
        } else {
            cout << b << endl;
        }
    }
    return 0;
}
