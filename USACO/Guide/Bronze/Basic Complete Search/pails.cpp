#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("pails");

    int X, Y, M;
    cin >> X >> Y >> M;

    int max_pour = 0;
    for (int i=0; i<(M-(M%X))/X+1; i++) {
        for (int j=0; j<(M-(M%Y))/Y+1; j++) {
            if (i * X + j * Y <= M) {
                max_pour = max(max_pour, i*X + j*Y);
            }
        }
    }

    cout << max_pour << '\n';
}