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
    setIO("div7");
	
	int N;
	cin >> N;
	
	vector<int> ids(N);
	vector<long long> prefixSum(N);
	for (int i=0; i<N; i++) {
		cin >> ids[i];

		if (i == 0) prefixSum[0] = ids[0];
		else prefixSum[i] = prefixSum[i-1] + ids[i];
	}

	int ret = 0;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N-i; j++) {
			if (abs(prefixSum[j+i] - prefixSum[j]) % 7 == 0) ret = max(ret, i);
		}
	}

	cout << ret << '\n';
}
