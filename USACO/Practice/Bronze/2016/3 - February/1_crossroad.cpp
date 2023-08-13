#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("crossroad");

    int N;
    cin >> N;

    vector<vector<int>> cows(10);
    for (int i = 0; i < N; i++) {
        int id, side;
        cin >> id >> side;

        cows[id-1].push_back(side);
    }

    int crossings = 0;
    for (int c=0; c<10; c++) {
        if (cows[c].size() > 0) {
            int current = cows[c][0];
            for (int i=1; i<cows[c].size(); i++) {
                if (cows[c][i] != current) {
                    crossings++;
                    current = !current;
                }
            }
        }
    }

    cout << crossings << '\n';
    return 0;
}
