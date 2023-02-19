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
    setIO("shuffle");
    int N;
    cin >> N;

    vector<int> directions(N);
    vector<int> cowID(N);

    for (int i=0; i<N; i++) {
        cin >> directions[i];
    }
    for (int i=0; i<N; i++) {
        cin >> cowID[i];
    }

    for (int i=0; i<3; i++) {
        for (int j=0; j<N; j++) {
            int backtrack = find(directions.begin(), directions.end(), j + 1) - directions.begin();
            int first = cowID[j];
            int last = cowID[backtrack];
            cowID[backtrack] = last;
            cowID[j] = first;
            
        }
    }

    for (int i=0; i<N; i++) {
        cout << cowID[i] << '\n';
    }
}