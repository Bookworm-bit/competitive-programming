#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("lifeguards");
	
	int N;
	cin >> N;

	vector<pair<int, int>> shifts(N);
	vector<int> times(1001, 0);
	for (int i=0; i<N; i++) {
		cin >> shifts[i].first >> shifts[i].second;

		for (int j=shifts[i].first; j<shifts[i].second; j++) {
			times[j]++;
		}
	}

	int largestCovered = 0;
	for (int i=0; i<N; i++) {
		for (int j=shifts[i].first; j<shifts[i].second; j++) {
			times[j]--;
		}

		int covered = 0;
		for (int j=0; j<1001; j++) {
			if (times[j] > 0) {
				covered++;
			}
		}

		for (int j=shifts[i].first; j<shifts[i].second; j++) {
			times[j]++;
		}

		largestCovered = max(largestCovered, covered);
	}

	cout << largestCovered << '\n';
}