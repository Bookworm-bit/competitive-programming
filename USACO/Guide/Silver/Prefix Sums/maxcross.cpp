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

int MAXN = (int) 1e5;

int main() {
    setIO("maxcross");
   
	int N, K, B;
	cin >> N >> K >> B;

	vector<int> prefixSum(N, 0);

	set<int> broken;
	for (int i=0; i<B; i++) {
		int temp;
		cin >> temp;

		broken.insert(temp);
	}

	int sum = 0;
	for (auto b : broken) {
		sum++;
		prefixSum[b-1] = sum;
	}

	int curr = prefixSum[0];
	for (int i=0; i<N; i++) {
		if (prefixSum[i] > curr) {
			curr = prefixSum[i];
		}

		prefixSum[i] = curr;
	}

	int ret = MAXN;
	for (int i=0; i<N-K; i++) {
		ret = min(ret, (prefixSum[i+K]-prefixSum[i]));
	}

	cout << ret << '\n';
}
