#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void setIO(string s) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("planting");

	int N;
	cin >> N;

	vector<int> counts(N, 0);
	for (int i=0; i<N-1; i++) {
		int a, b;
		cin >> a >> b;

		counts[a]++;
		counts[b]++;
	}

	cout << *max_element(counts.begin(), counts.end()) + 1 << '\n';
}