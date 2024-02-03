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

bool cmp(pair<string, int> a, pair<string, int> b) {
    return a.second < b.second;
}

int main() {
    //setIO("notlast");

    int N;
    cin >> N;

    // Bessie, Elsie, Daisy, Gertie, Annabelle, Maggie, and Henrietta
    map<string, int> cows;
    cows["Bessie"] = 0;
    cows["Elsie"] = 0;
    cows["Daisy"] = 0;
    cows["Gertie"] = 0;
    cows["Annabelle"] = 0;
    cows["Maggie"] = 0;
    cows["Henrietta"] = 0;
    for (int i=0; i<N; i++) {
        string n;
        int c;
        cin >> n >> c;

        cows[n] += c;
    }

    vector<pair<string, int>> vCows;
    for (auto p : cows) {
        vCows.push_back(p);
    }

    sort(vCows.begin(), vCows.end(), cmp);

    int minValue = (int) 1e9;
    int desiredValue = (int) 1e9;
    int nCows = 0;
    string cow;
    for (auto c : vCows) {
        cout << c.first << ' ' << c.second << '\n';
        if (minValue == (int) 1e9) {
            minValue = c.second;
        } else if (c.second > minValue && nCows == 0) {
            desiredValue = c.second;
            cow = c.first;
            nCows++;
        } else if (c.second == desiredValue) {
            nCows++;
        }
    }

    if (nCows == 1) {
        cout << cow << '\n';
    } else {
        cout << "Tie" << '\n';
    }
}