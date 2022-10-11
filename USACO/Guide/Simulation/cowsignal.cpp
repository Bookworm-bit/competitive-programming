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
    setIO("cowsignal");
    
    int M, K, N;
    cin >> M >> K >> N;

    vector<string> signal(M);
    for (int i = 0; i < M; i++) {
        cin >> signal[i];
    }

    for (string line : signal) {
        int xCount = count(line.begin(), line.end(), 'X');
        int fullstopCount = count(line.begin(), line.end(), '.');

        string newX = string(xCount * K, 'X');
        string newFullstop = string(fullstopCount * K, '.');

        for (int j=0; j<K; j++) {
            cout << newX + newFullstop << '\n';
        }
    }
    
}