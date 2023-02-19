#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int power(int idx) {
    int result = 1;
    for (int i=0; i<idx; i++) {
        result *= -2;
    }
    return result;
}

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

bool intersection(int x, int y, int idx) {
    int powTwo = power(idx);
    if (powTwo > 0) {
        return (x <= y && y <= x + powTwo) ? true : false;
    } else if (powTwo < 0) {
        return (x >= y && y >= x + powTwo) ? true : false;
    } else {
        return false;
    }
}

int main() {
    setIO("lostcow");

    int x, y;
    cin >> x >> y;

    int idx = 0;
    int distance = 0;
    while (!intersection(x, y, idx)) {
        distance += abs(power(idx+1));
        idx++;
    }
    distance += abs(y-x);
    cout << distance << '\n';
}