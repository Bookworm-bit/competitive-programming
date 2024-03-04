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

struct cow {
    int a, b;
};

bool cmp(cow x, cow y) {
    if (x.a == y.a) {
        return x.a < y.a;
    } else {
        return x.b < y.b;
    }
}

int main() {
    setIO("helpcross");

    int C, N;
    cin >> C >> N;

    vector<int> T(C);
    for (int i=0; i<C; i++) {
        cin >> T[i];
    }

    vector<cow> cows(N);
    for (int i=0; i<N; i++) {
        cin >> cows[i].a >> cows[i].b;
    }


    sort(cows.begin(), cows.end(), cmp);
    sort(T.begin(), T.end());

    int ret = 0;
    vector<bool> paired(N);
    for (int i=0; i<C; i++) {
        for (int j=0; j<N; j++) {
            if (T[i] >= cows[j].a && T[i] <= cows[j].b && !paired[j]) {
                paired[j] = true;
                ret++;
                break;
            }
        }
    }

    cout << ret << '\n';
}
