#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("balancing");

    int N, B;
    cin >> N >> B;

    vector<int> x_coords(N);
    vector<int> y_coords(N);
    for (int i=0; i<N; i++) {
        cin >> x_coords[i] >> y_coords[i];
    }

    vector<int> largest;
    vector<int> a;
    vector<int> b;
    for (int i=0; i<N; i++) {
        a.push_back(x_coords[i] - 1);
        b.push_back(y_coords[i] - 1);
    }
    for (int j=0; j<N; j++) {
        for (int k=0; k<N; k++) {
            vector<int> quadrant_count(4, 0);
            for (int i=0; i<N; i++) {
                if (x_coords[i] > a[j] && y_coords[i] > b[k]) {
                    quadrant_count[0]++;
                } else if (x_coords[i] > a[j] && y_coords[i] < b[k]) {
                    quadrant_count[1]++;
                } else if (x_coords[i] < a[j] && y_coords[i] < b[k]) {
                    quadrant_count[2]++;
                } else {
                    quadrant_count[3]++;
                }
            }
            largest.push_back(*max_element(quadrant_count.begin(), quadrant_count.end()));
        }     
    }
    cout << *min_element(largest.begin(), largest.end()) << '\n';
}