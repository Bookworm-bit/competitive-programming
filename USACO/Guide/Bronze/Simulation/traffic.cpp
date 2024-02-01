#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("traffic");

    int N;
    cin >> N;

    vector<string> actions(N);
    vector<vector<int>> ranges(N);
    for (int i=0; i<N; i++) {
        vector<int> range(2);
        cin >> actions[i] >> range[0] >> range[1];

        ranges[i] = range;
    }

    int lower_range_start = 0;
    int upper_range_start = 1e9;

    for (int i=N-1; i>=0; i--) {
        if (actions[i] == "none") {
            lower_range_start = max(lower_range_start, ranges[i][0]);
            upper_range_start = min(upper_range_start, ranges[i][1]);
        } else if (actions[i] == "off") {
            lower_range_start += ranges[i][0];
            upper_range_start += ranges[i][1];
        } else {
            lower_range_start -= min(ranges[i][1], lower_range_start);
            upper_range_start -= ranges[i][0], lower_range_start;
        }
    }

    int lower_range_end = 0;
    int upper_range_end = 1e9;

    for (int i=0; i<N; i++) {
        if (actions[i] == "none") {
            lower_range_end = max(lower_range_end, ranges[i][0]);
            upper_range_end = min(upper_range_end, ranges[i][1]);
        } else if (actions[i] == "on") {
            lower_range_end += ranges[i][0];
            upper_range_end += ranges[i][1];
        } else {
            lower_range_end -= min(ranges[i][1], lower_range_end);
            upper_range_end -= ranges[i][0];
        }
    }

    cout << lower_range_start << ' ' << upper_range_start << '\n';
    cout << lower_range_end << ' ' << upper_range_end << '\n';
}