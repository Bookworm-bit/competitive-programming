#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    int N;
    cin >> N;

    vector<string> boards(2*N);
    for (int i=0; i<N; i++) {
        cin >> boards[i] >> boards[i+1];
    }

    vector<int> letters(26);
    for (int i=0; i<26; i++) {
        vector<int> counts;

        for (auto word : boards) {
            auto n = count(word.begin(), word.end(), 'p');
        }
    }
}