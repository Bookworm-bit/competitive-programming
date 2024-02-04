#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int N, K;
	cin >> N >> K;

	vector<ll> d(N);
	for (int i=0; i<N; i++) {
		cin >> d[i];
	}

	ll ret = K + 1;
	for (int i=1; i<N; i++) {
		ret += min(d[i] - d[i-1], (ll) K + 1);
	}

	cout << ret << '\n';
}
