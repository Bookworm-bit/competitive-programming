#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int main() {
    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i].first;
        a[i].second = i+1;
    }

    sort(a.begin(), a.end(), cmp);

    for (int m=1; m<n-1; m++) {
        int l = 0;
        int r = n-1;

        int tempX = x - a[m].first;
        while (l != r) {
            if (a[l].first + a[r].first == tempX && l != m && r != m) {
                cout << a[l].second << ' ' << a[m].second << ' ' << a[r].second << '\n';
                return 0;
            } else if (a[l].first + a[r].first < tempX) {
                l++;
            } else {
                r--;
            }
        }
    }

    cout << "IMPOSSIBLE" << '\n';
}
