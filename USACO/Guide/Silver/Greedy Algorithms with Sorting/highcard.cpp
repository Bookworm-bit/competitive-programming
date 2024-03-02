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
    setIO("highcard");

	int N;
	cin >> N;

	map<int, bool> elsie;
	for (int i=1; i<2*N+1; i++) {
		elsie[i] = false;
	}

	for (int i=0; i<N; i++) {
		int temp;
		cin >> temp;

		elsie[temp] = true;
	}

	int ret = 0;
	int bessie = 0;
	for (int i=2*N; i>0; i--) {
		if (!elsie[i]) {
			bessie++;
		} else {
			if (bessie - ret > 0) {
				ret++;
			}			
		}
	}

	cout << ret << '\n';
}
