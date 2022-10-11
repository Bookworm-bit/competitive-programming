#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("mixmilk");

    int amount[3];
    int size[3];

    cin >> size[0] >> amount[0];
    cin >> size[1] >> amount[1];
    cin >> size[2] >> amount[2];

    for (int i=0; i<100; i++) {
        int overlap = min(amount[i % 3], size[(i+1) % 3] - amount[(i+1) % 3]);
        amount[i % 3] -= overlap;
        amount[(i+1) % 3] += overlap;
    }

    cout << amount[0] << '\n';
    cout << amount[1] << '\n';
    cout << amount[2] << '\n';
}