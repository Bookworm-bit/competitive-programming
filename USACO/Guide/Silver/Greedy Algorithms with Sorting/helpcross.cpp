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

struct range {
    int a, b;
};

bool cmp(range x, range y) {
    if (x.a != y.a) return x.a < y.a;
    else return x.b < y.b;
}

bool cmp2(range x, range y) {
    if (x.b != y.b) return x.b < y.b;
    else return x.a < y.a;
}

int main() {
    setIO("helpcross");

    int C, N;
    cin >> C >> N;

    vector<int> t(C);
    for (int i=0; i<C; i++) {
        cin >> t[i];
    }

    vector<range> cows(N);
    for (int i=0; i<N; i++) {
        int aj, bj;
        cin >> aj >> bj;
        range temp = {aj, bj};
        cows[i] = temp;
    }

    sort(t.begin(), t.end());
    sort(cows.begin(), cows.end(), cmp);

    int ret = 0;
    vector<bool> paired(N, false);
    for (int i=0; i<C; i++) {
        int low = 1e9+1;
        int high = -1;
        for (int j=0; j<N; j++) {
            if (t[i] >= cows[j].a && t[i] <= cows[j].b && !paired[j]) {
                ret++;
                paired[j] = true;
                break;
            }
        }

        
    }

    cout << ret << '\n';
}
