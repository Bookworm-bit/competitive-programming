#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> a(N);
    for (int i=0; i<N; i++) {
        cin >> a[i];
    }

    int delta = 0;
    int rem = 0;
    int add = 0;
    int ret = 0;
    for (int i=0; i<N; i++) {
        delta += add - rem;
        
        int adjusted = a[i] + delta;
        ret += abs(adjusted);
        
        if (adjusted > 0) {
            rem += adjusted;
            delta -= adjusted;
        } else if (adjusted < 0) {
            add -= adjusted;
            delta -= adjusted;
        }
    }
    cout << ret << '\n';
}
