#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("billboard");
    
    int billboard[4];
    int billboard2[4];
    int truck[4];

    cin >> billboard[0] >> billboard[1] >> billboard[2] >> billboard[3];
    cin >> billboard2[0] >> billboard2[1] >> billboard2[2] >> billboard2[3];
    cin >> truck[0] >> truck[1] >> truck[2] >> truck[3];

    int area = (billboard[2] - billboard[0]) * (billboard[3] - billboard[1]) + (billboard2[2] - billboard2[0]) * (billboard2[3] - billboard2[1]);
    
    if (billboard[0] >= truck[2] || billboard[2] <= truck[0] || billboard[1] >= truck[3] || billboard[3] <= truck[1]) {
        ;
    } else {
        area -= (min(billboard[2], truck[2]) - max(billboard[0], truck[0])) * (min(billboard[3], truck[3]) - max(billboard[1], truck[1]));
    }

    if (billboard[0] >= truck[2] || billboard[2] <= truck[0] || billboard[1] >= truck[3] || billboard[3] <= truck[1]) {
        ;
    } else {
        area -= (min(billboard2[2], truck[2]) - max(billboard2[0], truck[0])) * (min(billboard2[3], truck[3]) - max(billboard2[1], truck[1]));
    }
    cout << area << '\n';
}