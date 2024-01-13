#include <bits/stdc++.h>
using namespace std;

void divide(vector<int>& p, long long a, long long b, int i, int& n, long long& small) {
    if (i == n) {
        small = min(small, abs(a - b));
    } else {
        divide(p, a+p[i], b, i+1, n, small);
        divide(p, a, b+p[i], i+1, n, small);
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i=0; i<n; i++) {
        cin >> p[i];
    }

    long long small = 1e63;

    divide(p, 0, 0, 0, n, small);

    cout << small << '\n';
}