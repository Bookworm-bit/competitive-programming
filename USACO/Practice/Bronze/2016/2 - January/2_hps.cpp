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
    
    short wins1 = 0;
    short wins2 = 0;
    for (short i=0; i < N; i++) {
        if (games[i][0] - games[i][1] == 1 || games[i][0] - games[i][1] == -2) {
            wins1++;
        } else if (games[i][0] - games[i][1] == -1 || games[i][0] - games[i][1] == 2) {
            wins2++;
        }
    }

    short mostWins = max(wins1, wins2);

    cout << mostWins << '\n';
}