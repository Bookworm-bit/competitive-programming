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
    setIO("shuffle");
    int N;
    cin >> N;

    vector<int> pattern(N);
    vector<int> v(N);

    for (int i=0; i<N; i++) {
        cin >> pattern[i];
    }
    for (int i=0; i<N; i++) {
        cin >> v[i];
    }

    vector<int> u(N);
    for (int i=0; i<3; i++) {
        u = v;
        for (int i=0; i<v.size(); i++) {
            u[i] = v[pattern[i] - 1];
        }
        v = u;
    }

    for (int i=0; i<N; i++) {
        cout << v[i] << '\n';
    }
}