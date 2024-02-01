#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("billboard");

    int lawnmower[4];
    int cowfeed[4];

    // 0 = BL_x, 1 = BL_y, 2 = TR_x, 3 = TR_y
    cin >> lawnmower[0] >> lawnmower[1] >> lawnmower[2] >> lawnmower[3];
    cin >> cowfeed[0] >> cowfeed[1] >> cowfeed[2] >> cowfeed[3];

    int tarpArea = (lawnmower[2] - lawnmower[0]) * (lawnmower[3] - lawnmower[1]);

    if (cowfeed[2] >= lawnmower[2] && cowfeed[0] <= lawnmower[0]) {
        if ()
    } else if (cowfeed[3] >= lawnmower[3] && cowfeed[1] >= lawnmower[1]) {
        tarpArea -= ();
    }

    cout << tarpArea << '\n';
}