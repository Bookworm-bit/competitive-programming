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

const int MAXN = (int) 1e5+1;
int prefixSum[3][MAXN];

int main() {
	setIO("hps");

	int N;
	cin >> N;

	for (int i=0; i<N; i++) {
		char temp;
		cin >> temp;

		int idx = 69;
		if (temp == 'H') {
			idx = 0;
		} else if (temp == 'P') {
			idx = 1;
		} else {
			idx = 2;
		}

		for (int j=0; j<3; j++) {
			int prev = 0;
			if (i > 0) prev = prefixSum[j][i-1];

			prefixSum[j][i] = prev + (int) (j == idx);
		}
	}

	int maxSum = 0;
	for (int i=0; i<N; i++) {
		int maxLow = 0;
		int maxHigh = 0;
		for (int j=0; j<3; j++) {
			maxLow = max(maxLow, prefixSum[j][i]);
			maxHigh = max(maxHigh, prefixSum[j][N-1]-prefixSum[j][i]);
		}

		maxSum = max(maxSum, maxLow + maxHigh);
	}

	cout << maxSum << '\n';
}
