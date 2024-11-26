#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int N;
	cin >> N;

	vector<pair<int, int>> a(N);
	for (int i=0; i<N; i++) {
		int temp;
		cin >> temp;

		a[i] = make_pair(temp, i);
	}

	sort(a.begin(), a.end());

	map<int, int> truePos;
	for (int i=0; i<N; i++) {
		truePos[a[i].second] = i;
	}

	long long maxT = 0;
	for (int i=0; i<N; i++) {
		maxT += (i+1) * (long long) a[i].first;
	}

	vector<long long> pref(N, 0);
	for (int i=0; i<N; i++) {
		pref[i] = (long long) a[i].first;
		if (i > 0) pref[i] += pref[i-1];
	}

	int Q;
	cin >> Q;
	for (int _=0; _<Q; _++) {
		int x, y;
		cin >> x >> y;

		x--;
		x = truePos[x];
		
		int newLoc = lower_bound(a.begin(), a.end(), make_pair(y, -1)) - a.begin() - (int) (y > a[x].first);

		long long ret = maxT;
		ret -= (long long) (x+1) * a[x].first;
		ret += (long long) (newLoc+1) * y;

		if (newLoc < x) ret += pref[x-1] - ((newLoc > 0) ? pref[newLoc-1] : 0);
		else if (x < newLoc) ret -= pref[newLoc] - pref[x];
		
		cout << ret << '\n';
	}
}