#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("cbarn");

    int N;
    cin >> N;

    vector<int> r(N);
    for (int i=0; i<N; i++) {
        cin >> r[i];
    }

    int minimumDistance = 1e9;
    for (int i=0; i<N; i++) {
        int sum = 0;
        for (int j=0; j<N; j++) {
            if (i < j) { sum += r[j] * (abs(i-j)); }
            else if (i > j) { sum += r[j] * (N - abs(i-j)); }
        }
        minimumDistance = min(minimumDistance, sum);
    }

    cout << minimumDistance << '\n';
}