#include <vector>
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("measurement");

    int N;
    cin >> N;

    vector<int> unsorted_days;
    vector<int> unsorted_amounts;
    vector<string> unsorted_names;

    vector<int> sorted_days;
    vector<int> sorted_amounts;
    vector<string> sorted_names;

    for (int i=0; i<N; i++) {
        cin >> unsorted_days[i] >> unsorted_names[i] >> unsorted_amounts[i];
    }

    for (int i=0; i<N; i++) {
        int s = *min_element(unsorted_days.begin(), unsorted_days.end());
        sorted_days[i] = s;
        int s_idx;

        for (int j=0; j<N; j++) {
            if (unsorted_days[j] = s) {
                s_idx = j;
            }
        } 

        sorted_names[i] = unsorted_names[s_idx];
        sorted_amounts[i] = unsorted_amounts[s_idx];
    }

    int curr_max = -10000000;
    int moves = 0;
    for (int i=0; i<N; i++) {
        if (sorted_amounts[i] != curr_max) {
            curr_max = max(sorted_amounts[i], curr_max);
            moves++;
        }
    }
    cout << moves << '\n';
}
