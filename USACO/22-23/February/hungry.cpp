#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long N, T;
    cin >> N >> T;

    vector<long long> days(N), shipments(N);
    for (int i = 0; i < N; i++) {
        cin >> days[i] >> shipments[i];
    }

    int pos = 0;
    long long stonk = 0, eaten = 0;
    for (long long day = 1; day <= T; day++) {
        if (day == days[pos]) {
            stonk += shipments[pos];
            pos++;
        }
        if (stonk > 0) {
            stonk--;
            eaten++;
        }
    }
    cout <<eaten << '\n';
}
