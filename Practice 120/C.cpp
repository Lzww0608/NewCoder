#include <bits/stdc++.h>
using namespace std;
int v[200005], pos[200005], now[200005];
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        pos[i] = i;
        now[i] = i;
    }
    sort(pos + 1, pos + n + 1, [&](auto& a, auto& b){
        return v[a] < v[b];
    });
    int d = v[pos[1]] + v[pos[n]];
    for (int i = 1; i <= n - i + 1; i++) {
        if (d != v[pos[i]] + v[pos[n-i+1]]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    vector<pair<int,int>>ans;
    for (int i = 1; i <= n; i++) {
        if (pos[i] == i) continue;
        int t = pos[i];
        swap(now[i], now[t]);
        ans.push_back({i,t});
        now[now[i]] = t;
        now[now[t]] = i;
    }
    cout << ans.size() << endl;
    for (auto x : ans) 
        cout << x.first << " " << x.second << endl;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}