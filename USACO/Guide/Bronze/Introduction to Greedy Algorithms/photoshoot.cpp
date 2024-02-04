#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    string s;
    cin >> s;

    int ret = 0;
    for (int i=N-(N%2+1); i>=0; i-=2) {
        int even = 0;
        for (int j=1; j<=i; j+=2) {
            if (s[j] == 'G') even++;
        }

        int odd = 0;
        for (int j=0; j<i; j+=2) {
            if (s[j] == 'G') odd++;
        }

        if (odd > even) {
            reverse(s.begin(), s.begin()+i);
            ret++;
        }
    }

    cout << ret << '\n';
}