#include <bits/stdc++.h>
using namespace std;

void permute(string& s, string current, vector<int>& used, vector<string>& outputs) {
    if (current.size() == s.size()) {
        outputs.push_back(current);
    } else {
        for (int i=0; i<26; i++) {
            if (used[i] > 0) {
                used[i]--;
                permute(s, current + (char) ('a' + i), used, outputs);
                used[i]++;
            }
        }
    }
}

int main() {
    string s;
    cin >> s;

    vector<int> used(26, 0);
    for (char c : s) {
        used[c - 'a'] = count(s.begin(), s.end(), c);
    }

    vector<string> outputs;

    permute(s, "", used, outputs);

    cout << (int) outputs.size() << '\n';
    for (auto o : outputs) {
        cout << o << '\n';
    }
}