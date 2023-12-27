//https://ac.nowcoder.com/acm/contest/72266/D
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>>g(200005);
vector<int>dp(200005);
string color;
long long ans = 0;
void dfs1(int v, int fa) {
    int res = 1;
    for (int u : g[v]) {
        if (u == fa) continue;
        dfs1(u,v);
        if (color[u] == color[v]) {
            res += dp[u] - 1;
        } else {
            res += dp[u];
        }
    }
    dp[v] = res;
}

void dfs2(int v, int fa, int w) {
    long long tmp = dp[v];
    if (fa != -1) {
        if (color[v] == color[fa]) {
            tmp += w - 1;
        } else {
            tmp += w;
        }
    }
    for (int u : g[v]) {
        if (u == fa) continue;
        long long ctmp = tmp;
        if (color[u] == color[v]) {
            ctmp -= dp[u] - 1;
        } else {
            ctmp -= dp[u];
        }
        ans += abs(ctmp - dp[u]);
        dfs2(u,v,ctmp);
    }
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int n;
    cin >> n;
    cin >> color;
    
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }
    dfs1(0,-1);
    dfs2(0,-1,0);
    cout << ans << endl;
}