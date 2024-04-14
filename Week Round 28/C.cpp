#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;
int a[1005][1005] = {0};
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    int x, y;
    cin >> n >> m >> k;
    for (int t = 0; t < k; t++) {
        cin >> x >> y;
        x--;y--;
        for (int i = 0; i <= x; i++) {
            if (a[i][y] == 0) {
                a[i][y]++;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) {
                cout <<"*";
            } else {
                cout << ".";
            }
        }
        cout << '\n';
    }
    return 0;
}