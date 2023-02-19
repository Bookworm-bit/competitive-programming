#define nl '\n'
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> willing_tuition(n);
    for (int i=0; i<n; i++) {
        cin >> willing_tuition[i];
    }

    sort(willing_tuition.begin(), willing_tuition.end());

    vector<int> profit(n);
    for (int i=0; i<n; i++) {
        profit[i] = willing_tuition[i] * (n - i);
    }

    int max_profit = *max_element(profit.begin(), profit.end());
    cout << max_profit << " " << willing_tuition[find(profit.begin(), profit.end(), max_profit) - profit.begin()] << nl;
}