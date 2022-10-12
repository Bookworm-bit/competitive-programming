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
    setIO("speeding");
    
    int N, M;
    cin >> N >> M;
    
    vector<int> rawRoadSpeed(N);
    vector<int> rawRoadDistance(N);
    vector<int> rawBessieSpeed(M);
    vector<int> rawBessieDistance(M);

    vector<int> bessieSpeed(100);
    vector<int> roadSpeed(100);
    
    for (int i=0; i<N; i++) {
        cin >> rawRoadDistance[i] >> rawRoadSpeed[i];
    }
    for (int i=0; i<M; i++) {
        cin >> rawBessieDistance[i] >> rawBessieSpeed[i];
    }

    int idx = 0;
    for (int i=0; i<rawBessieDistance.size(); i++) {
        for (int j=0; j<rawBessieDistance[i]; i++) {
            bessieSpeed[idx] = rawBessieSpeed[i];
            // cout << bessieSpeed[idx] << '\n';
            idx++;
        }
    }
    int jdx = 0;
    for (int i=0; i<rawRoadDistance.size(); i++) {
        for (int j=0; j<rawRoadDistance[i]; i++) {
            roadSpeed[jdx] = rawRoadSpeed[i];
            // cout << roadSpeed[jdx] << '\n';
            jdx++;
        }
    }
    
    int maxInfraction = 0;
    for (int i=0; i<100; i++) {
        maxInfraction = max(maxInfraction, bessieSpeed[i] - roadSpeed[i]);
    }
    cout << maxInfraction << '\n';
}
