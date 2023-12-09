#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    int N;
    cin >> N;

    map<int, char> statements;
    set<int> positions;
    for (int i=0; i<N; i++) {
        int position;
        char direction;
        cin >> direction >> position;

        statements[position] = direction;
        positions.insert(position);
    }

    int liars = (int)1e9+1;
    for (int p : positions) {
        int c = 0;

        for (auto cow : statements) {
            if (cow.second == 'G') {
                if (p < cow.first) { c++; }
            } else {
                if (p > cow.first) { c++; }
            }
        }

        liars = min(liars, c);
    }

    cout << liars << '\n';
}