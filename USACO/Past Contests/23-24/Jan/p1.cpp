#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		vector<int> h;
		map<int, int> preferences;
		for (int i=0; i<N; i++) {
			int hi;
			cin >> hi;
			if (preferences.find(hi) == preferences.end()) {
				preferences[hi] = 1;
			} else {
				preferences[hi]++;
			}

			h.push_back(hi);
		}

		set<int> winners;
		for (auto p : preferences) {
			if (p.second > N / 2) {
				winners.insert(p.first);
				break;
			}
		}

		for (int i=0; i<N-2; i++) {
			if (h[i] == h[i+1] || h[i] == h[i+2]) winners.insert(h[i]);
            if (h[i+1] == h[i+2]) winners.insert(h[i+1]);
		}

		if (winners.size() >= 1) {
			bool first = true;
			for (int w : winners) {
				if (!first) {
					cout << " ";
				} else {
					first = false;
				}
				cout << w;
			}
			cout << '\n';
		} else {
			cout << -1 << '\n';
		}
		
	}
}