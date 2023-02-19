#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    double n;
    double m;
    double a;

    cin >> n >> m >> a;
    double na = n/a;
    double ma = m/a;

    long long ans = ceil(na) * ceil(ma);
    cout << fixed << ans;
}