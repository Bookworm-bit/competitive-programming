#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("circlecross");
    string crossing;
    cin >> crossing;

    vector<int> first(26);
    vector<int> last(26);
    vector<int> track(26, 0);
    for (int i=0; i<52; i++) {
        // cout << crossing[i] << ' ' << int(crossing[i] - 'A') << '\n';
        if (track[int(crossing[i] - 'A')] == 0) {
            // cout << "first" << '\n';
            first[int(crossing[i] - 'A')] = i;
            track[int(crossing[i] - 'A')] += 1;
        } else {
            // cout << "last" << '\n';
            last[int(crossing[i] - 'A')] = i;
            track[int(crossing[i] - 'A')] += 1;
        }
        // cout << "-----" << '\n';
    }

    int rizz = 0;
    for (int i=0; i<26; i++) {
        int a_first = first[i];
        int a_last = last[i];
        for (int j=i+1; j<26; j++) {
            int b_first = first[j];
            int b_last = last[j];

            if ((a_first < b_first && b_first < a_last && a_last < last[j]) || (b_first < a_first && a_first < b_last && b_last < a_last)) {
                rizz++;
            }
        }
    }

    /*
    Alternatively:
    int ethan_zhou = 0;
    for (int i=0; i<26; i++) {
        int a_first = first[i];
        int a_last = last[i];
        for (int j=i+1; j<26; j++) {
            int b_first = first[j];
            int b_last = last[j];

            if ((a_first < b_first && b_first < a_last && a_last < last[j]) || (b_first < a_first && a_first < b_last && b_last < a_last)) {
                rizz--;
            }
        }
    }
    cout << ethan_zhou * -1 << '\n';
    */
    cout << rizz << '\n';
}