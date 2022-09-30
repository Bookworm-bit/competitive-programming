#include <iostream>
#include <cstdio>
using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    setIO("paint");

    int a, b; // Farmer John
    int c, d; // Bessie da Cow uwu

    cin >> a >> b;
    cin >> c >> d;

    int sum = (b-a) + (d-c);
    int intersection = max(min(b, d) - max(a, c), 0);
    
    cout << sum - intersection << '\n';
}