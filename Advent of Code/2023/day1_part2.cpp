#include <bits/stdc++.h>
using namespace std;

int digitOf(char c, int idx, string s) {
    map<string, int> stringDigit;
    stringDigit.insert(pair<string, int>("one", 1));
    stringDigit.insert(pair<string, int>("two", 2));
    stringDigit.insert(pair<string, int>("three", 3));
    stringDigit.insert(pair<string, int>("four", 4));
    stringDigit.insert(pair<string, int>("five", 5));
    stringDigit.insert(pair<string, int>("six", 6));
    stringDigit.insert(pair<string, int>("seven", 7));
    stringDigit.insert(pair<string, int>("eight", 8));
    stringDigit.insert(pair<string, int>("nine", 9));

    if (isdigit(c)) {
        return (c - '0');
    } else {
        string word;
        for (int i=idx; i<(int) s.length(); i++) {
            if (isalpha(s[i])) {
                word += s[i];
                if (stringDigit.count(word) > 0) {
                    return stringDigit[word];
                }
            } else {
                break;
            }
        }
    }

    return 0;
}

int main() {
    int N = 1000;
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        for (int j=0; j<(int) s.length(); j++) {
            int change = digitOf(s[j], j, s);
            if (change > 0) {
                sum += 10 * change;
                break;
            }
        }

        for (int j=(int) s.length()-1; j >= 0; j--) {
            int change = digitOf(s[j], j, s);
            if (change > 0) {
                sum += change;
                break;
            }
        }
    }

    cout << sum << '\n';
}
