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
    setIO("factory");

	int N;
    cin >> N;

    vector<int> adj(N, -1);
    for (int i=0; i<N-1; i++) {
        int a, b;
        cin >> a >> b;
        
        adj[a-1] = b-1;
    }

    int c = 0;
    int ret = 0;
    for (int i=0; i<N; i++) {
        if (adj[i] == -1) {
            c++;
            ret = i;
        }
    }

    if (c == 1) {
        cout << ret + 1 << '\n';
    } else {
        cout << -1 << '\n';
    }
}
