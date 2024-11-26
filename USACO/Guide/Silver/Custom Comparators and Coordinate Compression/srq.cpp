#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int a[(int) 1e9];
    memset(a, 0, sizeof(a));

    int N, Q;
    cin >> N >> Q;
    for (int i=0; i<N; i++) {
        int l, r;
        ll v;
        cin >> l >> r >> v;

        a[l] += v;
        if (r < (int) 1e9) {
            a[r] -= v;
        }
    }

    ll curr = 0;
    for (int i=1; i<(int) 1e9; i++) {
        a[i] += curr;
    }

    for (int i=0; i<Q; i++) {
        int l, r;
        cin >> l >> r;

        ll ret = 0;
        for (int i=l; i<r; i++) {
            ret += a[i];
        }

        cout << ret << '\n';
    }
}