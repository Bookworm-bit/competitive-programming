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

struct stop {
    int x, c;
};

int main() {
    setIO("reststops");

    int L, N, rf, rb;
    cin >> L >> N >> rf >> rb;

    vector<stop> restStops(N);
    for (int i=0; i<N; i++) {
        int xi, ci;
        cin >> xi >> ci;

        stop temp = {xi, ci};
        restStops[i] = temp;
    }

    vector<int> locs;
    int temp = 0;
    for (int i=N-1; i>=0; i--) {
        if (restStops[i].c > temp) {
            temp = restStops[i].c;
            locs.push_back(i);
        }
    }

    ll prev = 0;
    ll ret = 0;
    for (int i=locs.size()-1; i>=0; i--) {
        ll bessieTime = (restStops[locs[i]].x - prev) * rb;
        ll fjTime = (restStops[locs[i]].x - prev) * rf;

        ret += restStops[locs[i]].c * (fjTime - bessieTime);
        prev = restStops[locs[i]].x;
    }

    cout << ret << '\n';
}
