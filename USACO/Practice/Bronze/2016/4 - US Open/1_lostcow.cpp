#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("lostcow");

    int x, y;
    cin >> x >> y;

    int move = 1;
    int distance = 0;
    int newX = x;
    int oldX;

    bool xRelativeY = (y > x) ? 1 : 0;
    while (true) {
        oldX = newX;
        newX = x + move;
        distance += abs(newX - oldX);
        
        if ((xRelativeY && newX >= y) || (!xRelativeY && newX <= y)) {
            distance -= abs(newX - y);
            break;
        }

        move *= -2;
    }

    cout << distance << '\n';
}
