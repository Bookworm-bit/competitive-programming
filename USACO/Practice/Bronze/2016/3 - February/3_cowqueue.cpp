#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

bool comparator(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int main() {
    setIO("cowqueue");

    int N;
    cin >> N;

    vector<pair<int, int>> cows(N);
    for (int i=0; i<N; i++) {
        cin >> cows[i].first >> cows[i].second;
    }

    sort(cows.begin(), cows.end(), comparator);

    int time = cows[0].first;
    for (int i=0; i<N; i++) {
        int arrivalTime = cows[i].first;
        int duration = cows[i].second;

        if (time <= arrivalTime) {
            time = arrivalTime + duration;
        } else {
            time += duration;
        }
    }

    cout << time << '\n';
}