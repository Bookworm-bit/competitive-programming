#include <bits/stdc++.h>
using namespace std;

void solve(string &s, int i, set<int> &stonks) {
    if (i == s.length()) {
        int boing = 0;
        for (int j=0; j<s.length()-1; j++) {
            if (s[j] == s[j+1]) {
                boing++;
            }
        }
        stonks.insert(boing);
        return;
    }

    if (s[i] == 'F') {
        s[i] = 'B';
        solve(s, i+1, stonks);
        s[i] = 'E';
        solve(s, i+1, stonks);
        s[i] = 'F';
    } else {
        solve(s, i+1, stonks);
    }
}


int main() {
    int n;
    string s;
    cin >> n >> s;

    set<int> stonks;
    solve(s, 0, stonks);

    cout << stonks.size() << endl;
    for (int x : stonks) {
        cout << x << endl;
    }
}
