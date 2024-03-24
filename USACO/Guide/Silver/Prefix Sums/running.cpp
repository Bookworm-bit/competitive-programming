#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> b(n);
		for (auto& bi : b) {
			cin >> bi;
		}

		vector<int> before(n);
		vector<int> after(n);

		for (int i=0; i<n; i++) {
			if (i == 0) {
				before[i] = b[i]+i+1;
			} else {
				before[i] = max(before[i-1], b[i]+i+1);
			}
		}

		for (int i=n-1; i>=0; i--) {
			if (i == n-1) {
				after[i] = b[i]-i-1;
			} else {
				after[i] = max(after[i+1], b[i]-i-1);
			}
		}

		int ret = 0;
		for (int i=1; i<n-1; i++) {
			ret = max(ret, b[i] + before[i-1] + after[i+1]);
		}

		cout << ret << '\n';
	}
}
