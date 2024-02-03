#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;

    vector<int> w(2*n); 
    for (int i=0; i<2*n; i++) {
        cin >> w[i];
    }
    
    sort(w.begin(), w.end());

    int ret = (int) 1e9;
    for (int i=0; i<2*n; i++) {
        for (int j=i+1; j<2*n; j++) {
            vector<int> temp;
            for (int k=0; k<2*n; k++) {
                if (k == i || k == j) continue;
                temp.push_back(w[k]);
            }

            int val = 0;
            for (int k=0; k<2*n; k+=2) {
                val += temp[k+1] - temp[k];
            }

            ret = min(val, ret);
        }
    }

    cout << ret << '\n';
}