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
    setIO("shell");
    
    int N;
    cin >> N;
    vector<int> a(N);
    vector<int> b(N);
    vector<int> g(N);
    
    int scores[3];
    bool shells[] = {false, false, false};
    
    for (int i=0; i<N; i++) {
        cin >> a[i] >> b[i] >> g[i];
    }

    for (int k=0; k<3; k++) {
        shells[0] = false;
        shells[1] = false;
        shells[2] = false;
        shells[k] = true;

        scores[k] = 0;

        for (int j=0; j<N; j++) {
            int position_a = shells[a[j] - 1];
            int position_b = shells[b[j] - 1];

            shells[b[j] - 1] = position_a;
            shells[a[j] - 1] = position_b;

            if (shells[g[j] - 1] == true) {
                scores[k]++;
            }
        }
    }

    cout << *max_element(scores, scores + 3) << '\n';
    return 0;
}