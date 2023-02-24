#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int cornersCovered(int cowfeed, int lawnmower) {
    ;
}

int main() {
    setIO("billboard");
    
    vector<int> lawnmowerCoords(4);
    vector<int> cowfeedCoords(4);

    cin >> lawnmowerCoords[0] >> lawnmowerCoords[1] >> lawnmowerCoords[2] >> lawnmowerCoords[3];
    cin >> cowfeedCoords[0] >> cowfeedCoords[1] >> cowfeedCoords[2] >> cowfeedCoords[3];

    int lawnmowerArea = (lawnmowerCoords[2] - lawnmowerCoords[0]) * (lawnmowerCoords[3] - lawnmowerCoords[1]);
}