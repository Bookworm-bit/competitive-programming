#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("blocks");

    int N;
    cin >> N;

    int alphabet[26] = {0};
    for (int i=0; i<N; i++) {
        string word1, word2;
        cin >> word1 >> word2;

        for (char c='a'; c<='z'; c++) {
            int count1 = count(word1.begin(), word1.end(), c);
            int count2 = count(word2.begin(), word2.end(), c);
            
            alphabet[c - 'a'] += max(count1, count2);
        }
    }

    for (int j=0; j<26; j++) {
        cout << alphabet[j] << '\n';
    }
}