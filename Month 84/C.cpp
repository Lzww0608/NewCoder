//https://ac.nowcoder.com/acm/contest/72389/C
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>
using namespace std;

bool existsNonDecreasingSequence(const vector<int>& a, int k) {
	int n = a.size();
	vector<int> b(n);

	// 初始化 b[0]
	b[0] = a[0] - k;

	// 构建 b 的其余部分
	for (int i = 1; i < n; ++i) {
		// b[i] 应尽可能接近 a[i]，但不小于 b[i-1]，且在 a[i] 和 a[i] - k 之间
		b[i] = max(b[i - 1], min(a[i] - k, a[i - 1] + k));

		// 检查是否可能构造出满足条件的 b[i]
		if (abs(a[i] - b[i]) > k) {
			return false; // 如果不满足条件，则不存在这样的序列
		}
	}

	return true;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		vector<int>arr(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		if (existsNonDecreasingSequence(arr, k)) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	return 0;
}
