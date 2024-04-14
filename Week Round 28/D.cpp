#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;
long long a[100005];
long long pre[100005] = {0};
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pre[i+1] = pre[i] + a[i];
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        int l = i, r = n;
        while(l < r) {
            int mid = l + ((r - l) >> 1);
            if (pre[mid] - pre[i] >= k) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        ans += n + 1 - l;
    }
    cout << ans << endl;
    return 0;
}