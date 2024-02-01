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
    // setIO("stacking");
    
    int N, K;
    cin >> N >> K;

    vector<int> stacks(N, 0);

    vector<int> differences(N, 0);
    for (int i=0; i<K; i++) {
        int a, b;
        cin >> a >> b;

        differences[a-1]++;
        differences[min(b, N-1)]--;
    }

    int curr = 0;
    for (int i=0; i<N; i++) {
        curr += differences[i];
        stacks[i] = curr;
    }

    sort(stacks.begin(), stacks.end());

    cout << stacks[N / 2] << '\n';
}
