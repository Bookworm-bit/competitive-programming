#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("gymnastics");

    int N, K;
    cin >> N >> K;
    
    vector<vector<int>> rankings(N);
    for (int i=0; i<N; i++) {
        for (int j=0; j<K; j++) {
            int place;
            cin >> place;
            rankings[i].push_back(place);
        }
    }

    int consistent = 0;
      
    for (int f=1; f<K+1; f++) {
        for (int s=1; s<K+1; s++) {
            int always_big = 0;
            int always_small = 0;
            for (int r=0; r<N; r++) {
                int c1f = find(rankings[r].begin(), rankings[r].end(), f) - rankings[r].begin();
                int c2f = find(rankings[r].begin(), rankings[r].end(), s) - rankings[r].begin();
                if (c1f > c2f) {
                    always_big++;
                } else if (c2f > c1f) {
                    always_small++;
                }
            }
            if (always_big == N || always_small == N) {
                consistent++;
            }
        }
    }
    cout << (int) consistent / 2 << '\n';
}