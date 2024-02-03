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
    setIO("whereami");

    int N;
    cin >> N;

    string s;
    cin >> s;

    for (int i=1; i<N; i++) {
        set<string> temp;
        for (int j=0; j<N-i+1; j++) {
            temp.insert(s.substr(j, i));
        }

        if (temp.size() == N-i+1) {
            cout << i << '\n';
            return 0;
        }
    }
}