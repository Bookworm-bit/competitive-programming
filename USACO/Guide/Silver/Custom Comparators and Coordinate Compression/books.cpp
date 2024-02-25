#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, T;
    cin >> N >> T;

    vector<int> pref(N+1, 0);
    for (int i=1; i<=N; i++) {
        cin >> pref[i];
        pref[i] += pref[i-1];
    }

    int l = 0;
    int r = 0;
    int ret = 0;
    while (r < N) {
        if (pref[r+1] - pref[l] <= T) {
            ret = max(ret, r - l + 1);
            r++;
        } else {
            l++;
        }
    }

    cout << ret << '\n';
}
