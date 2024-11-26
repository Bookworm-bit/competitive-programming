#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void setIO(string s) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

struct cow {
    int a;
    int b;
    int alone;
}

int main() {
    setIO("lifeguards");

    int N;
    cin >> N;

    vector<cow> cows;
    for (int i=0; i<N; i++) {
        int a, b;
        cin >> a >> b;

        cow temp = {a, b, 0};
        cows[i] = temp;        
    }

    
}