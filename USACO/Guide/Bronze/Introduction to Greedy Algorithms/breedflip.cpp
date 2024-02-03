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
    setIO("breedflip");

    int N;
    cin >> N;

    string a, b;
    cin >> a >> b;

    bool prev = false;
    int ret = 0;
    for (int i=0; i<N; i++) {
        if (a[i] != b[i]) {
            if (!prev) {
                ret++;
                prev = true;
            }
        } else {
            prev = false;
        }
    }

    cout << ret << '\n';
}