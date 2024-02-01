#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("censor");

    string message, bad;
    cin >> message;
    cin >> bad;

    string result = message.substr(0, bad.size());
    for (int i=bad.size(); i<message.size(); i++) {
        if (result.size() >= bad.size() && result.substr(result.size() - bad.size(), bad.size()) == bad) {
            result.erase(result.size() - bad.size());
        }

        result += message[i];
    }

    cout << result << '\n';
}