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
    setIO("diamond");

    long long n, k;
    cin >> n >> k;
    
    vector<long long> diamond(n);
    for (long long i=0; i<n; i++) {
        cin >> diamond[i];
    }

    sort(diamond.begin(), diamond.end());

    long long max_diamonds = 0;
    for (long long i=0; i<n; i++) {
        long long count = 0;
        for (long long j=i; j<n; j++) {
            if ((diamond[j] <= diamond[i] + k)) {
                count++;
            }
        }
        max_diamonds = max(max_diamonds, count);
    }
    
    cout << max_diamonds << '\n';
}