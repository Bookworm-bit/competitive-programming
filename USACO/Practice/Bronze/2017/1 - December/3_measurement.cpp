#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int nameToIndex(string name) {
    if (name == "Bessie") { return 0; }
    else if (name == "Elsie") { return 1; }
    else { return 2; }
}

int main() {
    setIO("measurement");

    int N;
    cin >> N;

    int milkLog[3][100] = {0};
    for (int i=0; i<N; i++) {
        int day, change;
        string name;
        int nameNum;

        cin >> day >> name >> change;
        nameNum = nameToIndex(name);

        milkLog[nameNum][day-1] = change;
    }

    for (int i=0; i<3; i++) {
        int latest = 0;
        for (int j=0; j<100; j++) {
             if (milkLog[i][j] != 0) {
                latest += milkLog[i][j];
            }
            milkLog[i][j] = latest;
        }
    }

    bool winners[3] = {false, false, false};
    int count = 0;
    for (int i=0; i<100; i++) {
        int largest = max({milkLog[0][i], milkLog[1][i], milkLog[2][i]});
        bool new_winners[3];

        for (int j=0; j<3; j++) {
            new_winners[j] = (milkLog[j][i] == largest) ? true : false;
        }
        if (new_winners[0] != winners[0] || new_winners[1] != winners[1] || new_winners[2] != winners[2]) {
            count++;
            winners[0] = new_winners[0];
            winners[1] = new_winners[1];
            winners[2] = new_winners[2];
        }
    }

    cout << count - (milkLog[0][0] == milkLog[1][0] && milkLog[1][0] == milkLog[2][0]) ? 1 : 0<< '\n';
}