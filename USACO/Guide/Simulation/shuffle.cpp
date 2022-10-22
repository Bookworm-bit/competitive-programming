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
    int N;
    cin >> N;

    vector<int> directions(N);
    vector<int> endPositions(N);

    for (int i=0; i<N; i++) {
        cin >> directions[i];
    }
    for (int i=0; i<N; i++) {
        cin >> endPositions[i];
    }

    
}