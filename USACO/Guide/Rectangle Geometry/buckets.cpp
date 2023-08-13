#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("buckets");

    int barn[2];
    int lake[2];
    int rock[2];
    for (int i=0; i<10; i++) {
        string line;
        cin >> line;

        for (int j=0; j<10; j++) {
            char c = line[j];

            if (c == 'B') {
                barn[0] = i;
                barn[1] = j;
            } else if (c == 'L') {
                lake[0] = i;
                lake[1] = j;
            } else if (c == 'R') {
                rock[0] = i;
                rock[1] = j;
            }
            
        }
    }

    int dx = max(barn[0], lake[0]) - min(barn[0], lake[0]);
    int dy = max(barn[1], lake[1]) - min(barn[1], lake[1]);

    int cows = dx + dy - 1;
    
    bool horizontalBlocked = (barn[1] == lake[1] && rock[1] == barn[1]) && (rock[0] < max(lake[0], barn[0]) && rock[0] > min(lake[0], barn[0]));
    bool verticalBlocked = (barn[0] == lake[0] && rock[0] == barn[0]) && (rock[1] < max(barn[1], lake[1]) && rock[1] > min(barn[1], lake[1]));
    if (horizontalBlocked || verticalBlocked) {
        cows += 2;
    }

    cout << cows << '\n';
}