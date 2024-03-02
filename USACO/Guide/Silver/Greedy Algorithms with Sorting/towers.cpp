#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;

	vector<int> k(n);
	for (auto &ki : k) {
		cin >> ki;
	}

	multiset<int> towers;
	int ret = 0;
	for (auto ki : k) {
		auto it = towers.upper_bound(ki);
		if (it != towers.end()) {
			towers.erase(it);
			towers.insert(ki);
		} else {
			towers.insert(ki);
			ret++;
		}
	}

	cout << ret << '\n';
}
