#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<vector<int>> forest(N, vector<int> (N, 0));
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            char c;
            cin >> c;

            forest[i][j] = (int) (c == '*');
        }
    }

    vector<vector<int>> pref(N, vector<int>(N, 0));
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            pref[i][j] = forest[i][j];
            if (i > 0) pref[i][j] += pref[i-1][j];
            if (j > 0) pref[i][j] += pref[i][j-1];
            if (i > 0 && j > 0) pref[i][j] -= pref[i-1][j-1];
        }
    }

    for (int i=0; i<Q; i++) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        y1--; x1--; y2--; x2--;

        int ret = pref[y2][x2];
        if (y1 > 0) ret -= pref[y1-1][x2];
        if (x1 > 0) ret -= pref[y2][x1-1];
        if (y1 > 0 && x1 > 0) ret += pref[y1-1][x1-1];
        cout << ret << '\n';
    }
}