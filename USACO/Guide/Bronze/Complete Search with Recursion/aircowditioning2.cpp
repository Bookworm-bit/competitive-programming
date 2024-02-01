#include <bits/stdc++.h>
using namespace std;

struct ACUnit {
    int start;
    int end;
    int cool;
    int money;
};

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> temperatures(100, 0);
    for (int i=0; i<N; i++) {
        int s, t, c;
        cin >> s >> t >> c;

        for (int j=s-1; j<=t-1; j++) {
            temperatures[j] = c;
        }
    }

    vector<ACUnit> ACUnits(M);
    for (int i=0; i<M; i++) {
        int a, b, p, m;
        cin >> a >> b >> p >> m;

        ACUnit temp;
        temp.start = a-1;
        temp.end = b-1;
        temp.cool = p;
        temp.money = m;

        ACUnits[i] = temp;
    }

    int minCost = (int) 1e9;
    for (int mask=0; mask<(1<<M); mask++) {
        vector<int> new_temperatures(100, 0);
        int cost = 0;
        for (int i=0; i<M; i++) {
            if (mask & (1 << i)) {
                for (int j=ACUnits[i].start; j<=ACUnits[i].end; j++) {
                    new_temperatures[j] += ACUnits[i].cool;
                }
                cost += ACUnits[i].money;
            }
        }

        int done = true;
        for (int i=0; i<100; i++) {
            if (temperatures[i] > new_temperatures[i]) {
                done = false;
                break;
            }
        }

        if (done) minCost = min(minCost, cost);
    }

    cout << minCost << '\n';
}