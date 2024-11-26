#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n, x;
	cin >> n >> x;

	vector<ll> pf(n);
    map<int, int> track;
	for (int i=0; i<n; i++) {
		int temp;
		cin >> temp;

		pf[i] = (ll) temp;
		if (i > 0) {
			pf[i] += pf[i-1];
		}

        if (track.find(x - pf[i]) == track.end()) {
            track[x - pf[i]] = 1;
        } else {
            track[x - pf[i]]++;
        }
	}

    int ret = 0;
    for (auto t : track) {
        if (track.find(x - t.first) != track.end()) {
            ret += min(t.second, trac[x - t.first]);
        }
    }

	cout << ret << '\n';
}
