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
    setIO("bcount");
   
    int N, Q;
    cin >> N >> Q;

    vector<int> cows(N);
    for (int i=0; i<N; i++) {
        cin >> cows[i];
    }

    vector<int> prefix_1(N+1, 0);
    vector<int> prefix_2(N+1, 0);
    vector<int> prefix_3(N+1, 0);

    for (int i=1; i<=N; i++) {
        if (i > 1) {
            prefix_1[i] = prefix_1[i-1] + (int) (cows[i-1] == 1);
            prefix_2[i] = prefix_2[i-1] + (int) (cows[i-1] == 2);
            prefix_3[i] = prefix_3[i-1] + (int) (cows[i-1] == 3);
        } else {
            prefix_1[1] = (int) (cows[i-1] == 1);
            prefix_2[1] = (int) (cows[i-1] == 2);
            prefix_3[1] = (int) (cows[i-1] == 3);   
        }
    }

    for (int i=0; i<Q; i++) {
        int a, b;
        cin >> a >> b;

        cout << prefix_1[b] - prefix_1[a-1] << ' ' << prefix_2[b] - prefix_2[a-1] << ' ' << prefix_3[b] - prefix_3[a-1] << '\n';
    }
}
