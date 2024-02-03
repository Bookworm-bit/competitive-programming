#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

void flip(vector<vector<int>> &cows, int a, int b) {
    for (int i=0; i<=a; i++) {
        for (int j=0; j<=b; j++) {
            cows[i][j] = !cows[i][j];
        }
    }
}

int main() { 
    setIO("outofplace");

    int N;
    cin >> N;

    vector<int> c(N);
    vector<int> sortedC(N);
    for (int i=0; i<N; i++) {
        int temp;
        cin >> temp;

        c[i] = temp;
        sortedC[i] = temp;
    }

    sort(sortedC.begin(), sortedC.end());

    int ret = 0;
    for (int i=0; i<N; i++) {
        if (c[i] != sortedC[i]) ret++;
    }

    cout << ret - 1 << '\n';
}