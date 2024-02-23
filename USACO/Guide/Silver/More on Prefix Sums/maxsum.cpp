#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;

    vector<ll> pref(N);
    for (int i=0; i<N; i++) {
        ll temp;
        cin >> temp;

        pref[i] = temp + (i != 0) * pref[i-1];
    }

    ll ret = pref[0];
    ll minPref = 0;
    for (int i=0; i<N; i++) {
        ret = max(ret, pref[i] - minPref);
        minPref = min(minPref, pref[i]);
    }

    cout << ret << '\n';
}