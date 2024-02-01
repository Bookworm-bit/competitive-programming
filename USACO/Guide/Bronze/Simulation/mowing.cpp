#include <bits/stdc++.h>
using namespace std;

int directionToNumber(char c) {
    if (c == 'N') {
        return 0;
    } else if (c == 'E') {
        return 1;
    } else if (c == 'S') {
        return 2;
    } else {
        return 3;
    }
}

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("mowing");

    int N;
    cin >> N;

    vector<vector<int>> moves(N);
    for (int i = 0; i < N; i++) {
        char direction;
        int move;

        cin >> direction >> move;
        vector<int> entry = {directionToNumber(direction), move};
        moves[i] = entry;
    }

    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<int>> path = {{0, 0}};
    int x = 1e9;
    for (int i=0; i<N; i++) {
        for (int j=0; j<moves[i][1]; j++) {
            vector<int> coordinate = {path.back()[0] + directions[moves[i][0]][0], path.back()[1] + directions[moves[i][0]][1]};

            for (int k=path.size()-1; k>=0; k--) {
                if (path[k][0] == coordinate[0] && path[k][1] == coordinate[1]) {
                    x = min(x, static_cast<int>(path.size() - k));
                }
            }

            path.push_back(coordinate);
        }
    }

    if (x == 1e9) { x = -1; }

    cout << x << '\n';

    return 0;
}
