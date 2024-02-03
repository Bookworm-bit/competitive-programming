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
    setIO("cowtip");

    int N;
    cin >> N;

    vector<vector<int>> cows(N, vector<int> (N));
    for (int i=0; i<N; i++) {
        string line;
        cin >> line;

        vector<int> row(N);
        for (int j=0; j<N; j++) {
            row[j] = line[j] - '0';
        }

        cows[i] = row;
    }

    int flips = 0;
    for (int i=N-1; i>=0; i--) {
        for (int j=N-1; j>=0; j--) {
            if (cows[i][j] == 1) {
                flip(cows, i, j);
                
                flips++;
            }
        }
    }

    cout << flips << '\n';
}