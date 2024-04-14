#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<string>ans;
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n - 1; i++) {
        ans.push_back(s.substr(i,2));
    }
    sort(ans.begin(),ans.end());
    for (auto& x : ans) {
        cout << x << endl;
    }
    return 0;
}