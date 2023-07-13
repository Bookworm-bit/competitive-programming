#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("square");

    int originalSquare[4];
    int newSquare[4];

    cin >> originalSquare[0] >> originalSquare[1] >> originalSquare[2] >> originalSquare[3];
    cin >> newSquare[0] >> newSquare[1] >> newSquare[2] >> newSquare[3];

    int smallestX = min(originalSquare[0], newSquare[0]);
    int smallestY = min(originalSquare[1], newSquare[1]);
    int largestX = max(originalSquare[2], newSquare[2]);
    int largestY = max(originalSquare[3], newSquare[3]);

    cout << max(largestX - smallestX, largestY - smallestY) * max(largestX - smallestX, largestY - smallestY) << '\n';
}