#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> a(N);
    for (int i=0; i<N; i++) {
        cin >> a[i];
    }

    long long ret = 0;
    for (int i=0; i<N; i++) {
        ret += abs(a[i]);

        long long power = N - i;

        if (a[i] == 0) continue;
        
        for (int j=N-1; j>=1; j--) {
            if (power == 0) break;

            a[j] += -a[i] * power;
            power--;
        }

        a[i] = 0;
    }

    cout << ret << '\n';
}
