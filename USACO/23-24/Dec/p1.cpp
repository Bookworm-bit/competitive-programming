#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M;
    cin >> N >> M;

    vector<long long> cows(N, 0);
    vector<int> idx;
    int largest = 0;
    for (int i=0; i<N; i++) {
        cin >> cows[i];
        if (cows[i] > largest) {
            idx.push_back(i);
            largest = max(i, largest);
        }
    }

    vector<long long> canes(M);
    for (int i=0; i<M; i++) {
        cin >> canes[i];
    }

    for (int i=0; i<M; i++) {
        long long eaten = 0;

        for (auto j : idx) {
            if (cows[j] - eaten > 0) {
                long long cowEats = min(cows[j] - eaten, canes[i] - eaten);

                cows[j] += cowEats;
                eaten += cowEats;

                if (eaten == canes[i]) break;
            }
        }
    }

    for (auto c : cows) {
        cout << c << '\n';
    }
}