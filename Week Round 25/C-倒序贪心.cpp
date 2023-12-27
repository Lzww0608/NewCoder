//https://ac.nowcoder.com/acm/contest/72266/C
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int mod = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    long long ans = 0;
    for (int i = n-3; i >= 0; i--) {
            // 检查是否可以使用踏前斩攻击
            if (i + 2 < n && a[i] >= 1 && a[i + 1] >= 2 && a[i + 2] >= 3) {
                // 计算每个怪物可以承受的踏前斩次数
                int t1 = a[i]; // 当前怪物
                int t2 = a[i + 1] / 2; // 下一个怪物
                int t3 = a[i + 2] / 3; // 下下个怪物

                // 确定最大可用的踏前斩次数
                long long t = min({t1, t2, t3});

                ans += (5 * t); // 累加mp消耗
                // 减少怪物血量
                a[i] -= t;
                a[i + 1] -= 2 * t;
                a[i + 2] -= 3 * t;
            }
    }
    for (long long x : a) {
        ans += x;
    }

    cout << ans << endl;
    return 0;
}
