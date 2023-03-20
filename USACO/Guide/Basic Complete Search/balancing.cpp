#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("balancing");

    long long N, B;
    cin >> N >> B;

    vector<vector<int>> coordinates;
    for (int i=0; i<N; i++) {
        vector<int> spot(2);
        cin >> spot[0] >> spot[1];
        coordinates.push_back(spot);
    }

    vector<long double> dev;
    vector<long long> smallest;
    for (int a=0; a<B+1; a+=2) {
        for (int b=0; b<B+1; b+=2) {
            vector<long long> quadrant_count(4, 0);
            for (int i=0; i<N; i++) {
                vector<int> spot = coordinates[i];
                if (spot[0] > a && spot[1] > b) {
                    quadrant_count[0]++;
                } else if (spot[0] > a && spot[1] < b) {
                    quadrant_count[1]++;
                } else if (spot[0] < a && spot[1] < b) {
                    quadrant_count[2]++;
                } else {
                    quadrant_count[3]++;
                }
            }

            long double mean = static_cast<long double> (accumulate(quadrant_count.begin(), quadrant_count.end(), 0.0)) / 4.0;
            cout << "mean = " << mean << endl;
            cout << "quadrant_count[0] = " << quadrant_count[0] << endl;
            cout << "quadrant_count[1] = " << quadrant_count[1] << endl;
            cout << "quadrant_count[2] = " << quadrant_count[2] << endl;
            cout << "quadrant_count[3] = " << quadrant_count[3] << endl;
            long double mad = (abs(mean - quadrant_count[0]) + abs(mean - quadrant_count[1]) + abs(mean - quadrant_count[2]) + abs(mean - quadrant_count[3]));
            dev.push_back(mad);
            cout << "mad = " << mad << endl;
            smallest.push_back((long long) *min_element(quadrant_count.begin(), quadrant_count.end()));
        }   
    }

    long double smallest_dev = *min_element(dev.begin(), dev.end());
    long long thing = 1000000000000000000;
    long double eps = 1e-5;
    for (long long i=0; i<dev.size(); i++) {
        if (abs(dev[i] - smallest_dev) < eps) {
            thing = min(smallest[i], thing);
        }
    }
    cout << thing << '\n';
}