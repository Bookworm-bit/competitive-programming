#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    long long T;
    cin >> N >> T;

    vector<long long> d;
    vector<int> b;
    for (int i=0; i<N; i++) {
        int d, b;
        cin >> d >> b;
    }

    long long leftover = 0;
    long long eaten = 0;
    for (int i=0; i<N-1; i++) {
        long long gap = d[i+1] - d[i];

        if (b[i+1] + b[i] - gap >= 0) {
            leftover += b[i+1] + b[i] - gap;
            eaten += gap;
        } else {
            eaten += b[i+1] + b[i+1]
            eaten += min(gap - (b[i+1] + b[i+1]), leftover);
            leftover -= min(gap - (b[i+1] + b[i+1]), leftover);
        }
    }

    cout << eaten << '\n';
}