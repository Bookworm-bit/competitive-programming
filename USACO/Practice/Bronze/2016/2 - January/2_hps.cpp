#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() { 
    setIO("hps");

    short N;
    cin >> N;

    short games[N][2];
    for (short i=0; i<N; i++) {
        cin >> games[i][0] >> games[i][1];
    }

    short mostWins = -1;
    for (short i=0; i<3; i++) {
        short cow1Wins = 0;
        for (short j=0; j<N; j++) {
            if (games[j][0] == i) {
                games[j][0] += 3;
            } else if (games[j][1] == i) {
                games[j][1] += 3; 
            }

            if (games[j][0] - games[j][1] == 1 || games[j][0] - games[j][1] == -2) {
                cow1Wins++;
            }
        }

        mostWins = max(cow1Wins, mostWins);
    }

    cout << mostWins << '\n';
}