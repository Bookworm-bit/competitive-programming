#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;

    set<int> x;
    for (int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        x.insert(temp);
    }

    cout << x.size() << '\n';
}
