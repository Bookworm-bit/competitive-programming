#include <bits/stdc++.h>
using namespace std;

int xCompare(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int yCompare(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
	int N;
    cin >> N;
    
    vector<pair<int, int>> east;
    vector<pair<int, int>> north;

    map<pair<int, int>, int> cows;
    vector<pair<int, int>> order(N);
    for (int i=0; i<N; i++) {
        char direction;
        cin >> direction;

        pair<int, int> coords;
        cin >> coords.first >> coords.second;
        if (direction == 'N') {
            north.push_back(coords);
        } else {
            east.push_back(coords);
        }

        cows[coords] = -1;
        order[i] = coords;
    }

    sort(north.begin(), north.end(), xCompare);
    sort(east.begin(), east.end(), yCompare);

    for (int i=0; i<east.size(); i++) {
        for (int j=0; j<north.size(); j++) {
            pair<int, int> c1 = east[i];
            pair<int, int> c2 = north[j];
            
            if (cows[c2] != -1) continue;

            if (c1.first < c2.first && c1.second > c2.second) {
                int d1 = c2.first - c1.first;
                int d2 = c1.second - c2.second;

                if (d1 > d2) {
                    cows[c1] = d1;
                    break;
                } else if (d2 > d1) {
                    cows[c2] = d2;
                }
            }
        }
    }

    for (auto c : order) {
        if (cows[c] == -1) {
            cout << "Infinity" << '\n';
        } else {
            cout << cows[c] << '\n';
        }
    }
}
