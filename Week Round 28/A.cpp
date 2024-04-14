#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int a;
    int ans = 0;
    for (int i = 0; i < 6; i++) {
        cin >> a;
        ans += a;
    }
    cout << ans << endl;
    return 0;
}