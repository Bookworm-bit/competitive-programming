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
    cin >> M >> N >> K;

    vector<string> signal(M);
    for (int i = 0; i < M; i++) {
        cin >> signal[i];
    }

    for (string line : signal) {
        string broadcast = "";

        for (int i=0; i<N; i++) {
            broadcast += string(K, line[i]);
        }
        for (int j=0; j<K; j++) {
            cout << broadcast << '\n';
        }
    }
    
}
