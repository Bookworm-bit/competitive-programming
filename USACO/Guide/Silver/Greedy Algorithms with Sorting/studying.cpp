#include <bits/stdc++.h>
using namespace std;

int main() {
	int X, N;
	cin >> N >> X;

	vector<int> a(N);
	for (auto &ai : a) {
		cin >> ai;
	}

	sort(a.begin(), a.end());

	int curr = 0;
	int ret = 0;
	for (auto ai : a) {
		curr += ai;

		if (curr > X) {
			break;
		} else if (curr == X) {
			ret++;
			break;
		} else {
			ret++;
		}
	}

	cout << ret << '\n';
}
