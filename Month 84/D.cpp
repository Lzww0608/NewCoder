//https://ac.nowcoder.com/acm/contest/72389/D
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	vector<int> prefix01(n, 0);
	for (int i = 1; i < n; ++i) {
		prefix01[i] = prefix01[i - 1] + (s[i] == '0' && s[i - 1] == '1');
	}
	if (s.back() == '1') prefix01[n - 1]++;

	while (q--) {
		int l, r;
		cin >> l >> r;
		l--; r--;

		int ans = prefix01[n - 1]; // 初始化答案为总的'01'模式数量

		// 检查翻转前后边界处字符对'01'模式的影响
		if (l > 0 && s[l] == '0' && s[l - 1] == '1') ans--;
		if (r < n - 1 && s[r] == '0' && s[r + 1] == '1') ans--;

		if (l > 0 && s[r] == '0' && s[l - 1] == '1') ans++;
		if (r < n - 1 && s[l] == '0' && s[r + 1] == '1') ans++;

		// 计算翻转后末尾是否为'1'的影响
		//if (r == n - 1 && s[l] == '1') ans++;
		//if (l == 0 && s[r] == '1') ans--;

		cout << ans << endl;
	}

	return 0;
	return 0;
}
