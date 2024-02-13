#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<string> sick;
    string group = "";
    
    int count = 0;
    
    for (int i=0; i<N; i++) {
        char c;
        cin >> c;

        if (c - '0') {
            group += c;
        } else {
            if (!group.empty()) {
                sick.push_back(group);
                group = "";
            }
        }
    }

    if (!group.empty()) {
        sick.push_back(group);
    }

    int minSize = (int)1e9 + 1;
    for (string s : sick) {
        minSize = min(minSize, static_cast<int>(s.length()));
    }

    int maxDays = (minSize - 1) / 2;

    for (string s : sick) {
        for (int i=1; i<static_cast<int>(s.length())+1; i++) {
            if (i + i * (2 * maxDays + 1) >= static_cast<int>(s.length())) {
                count += i;
                break;
            }
        }
    }

    cout << count << '\n';
}
