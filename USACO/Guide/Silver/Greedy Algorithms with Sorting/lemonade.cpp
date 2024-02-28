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
  setIO("lemonade");
	int N;
	cin >> N;

	vector<int> w(N);
	for (auto &wi : w) {
		cin >> wi;
	}

	sort(w.rbegin(), w.rend());

	int c = 0;
	for (int i=0; i<N; i++) {
		if (c <= w[i]) c++;
	}

	cout << c << '\n';
}
